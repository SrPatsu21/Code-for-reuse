package menu;

import cards.Card;
import cards.Fight;
import dimension_controler.RoundButton;
import dimension_controler.Vec2;
import edu.princeton.cs.algs4.Draw;
import players.Enemy;
import players.Player;
import players.Slot;

import java.awt.*;

public class GameScene
{
	public final int RESOLUTION_X;
	public final int RESOLUTION_Y;
	public final Color BACKGROUND = Color.green;
	public final Color HANDOCOLOR = Color.RED;
    private Draw draw;
    private Player player;
	private Enemy enemy;
	private Slot selected_hand_card;
	private Slot selected_table_card;
	public static RoundButton round_button;
	private int turn_cont = 0;
	private Fight fight;
	private boolean game_stop = false;
	private boolean play_fist = false;

    public GameScene(Draw draw, int resolution_x, int resolution_y){
		this(draw, resolution_x, resolution_y, 0, 2);
	}
    public GameScene(Draw draw, int resolution_x, int resolution_y, int turnN, int turn_cont)
    {
		this.RESOLUTION_X = resolution_x;
		this.RESOLUTION_Y = resolution_y;
		setDraw(draw);
		getDraw().clear(BACKGROUND);
		setRoundButton(new RoundButton(getDraw(),
				new Vec2((int)(resolution_x-(resolution_x*0.15)), (int)(resolution_y-(resolution_y*0.55))),
				new Vec2((int)(resolution_x-(resolution_x*0.05)), (int)(resolution_y-(resolution_y*0.45))),
				turnN, BACKGROUND)
		);
		setTurnCont(turn_cont);
		setPlayer(new Player(draw, resolution_x, resolution_y, BACKGROUND, HANDOCOLOR));
		getPlayer().initPlayer();
		setEnemy(new Enemy(draw, resolution_x, resolution_y, BACKGROUND, HANDOCOLOR));
		getEnemy().initPlayer();
		setFight( new Fight());
		roundController();

		//client
		getPlayer().redraw();
		getEnemy().redraw();
    }

	//gettter setter
    public Draw getDraw()
    {
		return draw;
	}

	public void setDraw(Draw draw) {
		this.draw = draw;
	}

	public static RoundButton getRoundButton() {
		return round_button;
	}

	public static void setRoundButton(RoundButton round_button) {
		GameScene.round_button = round_button;
	}

	public Player getPlayer() {
		return player;
	}

	public void setPlayer(Player player) {
		this.player = player;
	}

	public int getTurnCont() {
		return turn_cont;
	}

	public void setTurnCont(int turn_cont) {
		this.turn_cont = turn_cont;
	}

	public Enemy getEnemy() {
		return enemy;
	}

	public void setEnemy(Enemy enemy) {
		this.enemy = enemy;
	}

	public Fight getFight() {
		return fight;
	}

	public void setFight(Fight fight) {
		this.fight = fight;
	}

	public Slot getSelectedHandCard() {
		return selected_hand_card;
	}

	public void setSelectedHandCard(Slot selected_hand_card) {
		this.selected_hand_card = selected_hand_card;
	}

	public Slot getSelectedTableCard() {
		return selected_table_card;
	}

	public void setSelectedTableCard(Slot selected_table_card) {
		this.selected_table_card = selected_table_card;
	}

	public boolean isPlay_fist() {
		return play_fist;
	}

	public void setPlay_fist(boolean play_fist) {
		this.play_fist = play_fist;
	}

	//round
	public void roundController() {
		if (getTurnCont() == 0) {
			setTurnCont(1);
			getEnemy().autoPlay();
			getRoundButton().redrawRound("pass");
			//AI
			if(isPlay_fist()) {
				getEnemy().autoPlay();
			}
		} else if(getTurnCont() == 1) {
			setTurnCont(2);
			getRoundButton().redrawRound("fight");
			//AI
			setPlay_fist(!isPlay_fist());
		} else if (getTurnCont() == 2) {
			setTurnCont(0);
			getFight().setPlayer(getPlayer());
			getFight().setEnemy(getEnemy());
			getFight().fight();
			if (getPlayer().getPlayerStatus().getLife() == 0 || getEnemy().getPlayerStatus().getLife() == 0) {
				this.game_stop = true;
				redraw();
			}else {
				//energy
				getPlayer().receiveEnergyBeforeRound(getRoundButton().getRound() + 1);
				getEnemy().receiveEnergyBeforeRound(getRoundButton().getRound() + 1);
				//cards
				getPlayer().getHand().verifySlots();
				getEnemy().getHand().verifySlots();
				getPlayer().getHand().addCard();
				getEnemy().getHand().addCard();
				if (getRoundButton().getRound() >= 5)
				{
					getPlayer().getHand().addCard();
					getEnemy().getHand().addCard();
				}
				//button
				getRoundButton().passRound();
				getRoundButton().redrawRound("pass");
				//AI
				if (!isPlay_fist()) {
					getEnemy().autoPlay();
				}
			}
		}
	}

	public void endGameMessage() {
		if (getPlayer().getPlayerStatus().getLife() == 0 || getEnemy().getPlayerStatus().getLife() == 0) {
			getDraw().setPenColor(Draw.BLUE);
			if(getPlayer().getPlayerStatus().getLife() == 0 && getEnemy().getPlayerStatus().getLife() == 0) {
				getDraw().text(RESOLUTION_X*0.5, RESOLUTION_Y*0.6, "I could say u lost anyway", 25);
			} else if (getEnemy().getPlayerStatus().getLife() == 0) {
				getDraw().text(RESOLUTION_X*0.5, RESOLUTION_Y*0.6, "U WIN", 25);
			}else if (getPlayer().getPlayerStatus().getLife() == 0) {
				getDraw().text(RESOLUTION_X*0.5, RESOLUTION_Y*0.6, "U LOST to a shito AI", 25);
			}
			getDraw().show();
		}
	}

	public void resetSelectedCardsToNull() {
		setSelectedTableCard(null);
		setSelectedHandCard(null);
	}

	public void swapSelectedCardsOnTable(int i) {
		Card aux = getSelectedTableCard().getCard();
		getSelectedTableCard().setCard(getPlayer().getTable().getSlotPos()[i].getCard());
		getPlayer().getTable().getSlotPos()[i].setCard(aux);
	}

	//clear draw
	public void clearArea(Vec2 start, Vec2 end, Color color) {
		getDraw().setPenColor(color);
		getDraw().filledPolygon(new double[]{start.getX(), end.getX()}, new double[]{start.getY(), end.getY()});
	}

	public void redraw() {
		getPlayer().redraw();
		getEnemy().redraw();
		if (this.game_stop) {
			endGameMessage();
		}
	}

	//mouse events
    public void mousePressed(double x, double y)
    {
		if (!game_stop) {
			//table button
			if (getPlayer().getTable().getButton().isInside((int)x, (int)y)) {
				for(int i = 0; i < getPlayer().getTable().SLOTSN; i++) {
					if(getPlayer().getTable().getSlotPos()[i].getButton().isInside(x, y)) {
						if(getSelectedTableCard() != null) {
							swapSelectedCardsOnTable(i);
							resetSelectedCardsToNull();
							getPlayer().getHand().verifySlots();
							redraw();
						} else if(getSelectedHandCard() != null) {
							if (getPlayer().getPlayerStatus().getEnergy() >= getSelectedHandCard().getCard().getEnergy_cost() && getPlayer().getTable().getSlotPos()[i].getCard() == null) {
								getPlayer().getPlayerStatus().removeEnergy(getSelectedHandCard().getCard().getEnergy_cost());
								getPlayer().getTable().getSlotPos()[i].setCard(getSelectedHandCard().getCard());
								getSelectedHandCard().setCard(null);
							}
							resetSelectedCardsToNull();
							redraw();
						} else {
							setSelectedTableCard(getPlayer().getTable().getSlotPos()[i]);
							if (getSelectedTableCard().getCard() != null) {
								getPlayer().getTable().redrawOneCard(getPlayer().getTable().getSlotPos()[i], Color.YELLOW);
							}
						}
					}
				}
			}
			//hand button
			else if (getPlayer().getHand().getHand_pos().isInside((int)x, (int)y)) {

				if (getSelectedTableCard() != null) {
					redraw();
					resetSelectedCardsToNull();
				} else if (getTurnCont() != 2) {
					for(int i = 0; i < getPlayer().getHand().HAND_SIZE; i++) {
						if(getPlayer().getHand().getSlot()[i].getButton().isInside(x, y)) {
							redraw();
							if (getPlayer().getHand().getSlot()[i].getCard() != null) {
								setSelectedHandCard(getPlayer().getHand().getSlot()[i]);
								getPlayer().getHand().redrawOneCard(getSelectedHandCard(), Color.YELLOW);
							}
						}
					}
				}
			}
			//button round
			else if(getRoundButton().isInside((int)x, (int)y)) {
				roundController();
				resetSelectedCardsToNull();
				redraw();
			}
		}else {
			//call a new screen to a new game or load
		}
	}
}
