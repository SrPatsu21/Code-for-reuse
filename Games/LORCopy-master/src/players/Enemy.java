package players;

import edu.princeton.cs.algs4.Draw;

import java.awt.*;

public class Enemy extends Player
{
    public Enemy(Draw draw, int resolution_x, int resolution_y, Color background, Color handcolor)
    {
        super(draw, resolution_x, resolution_y, background, handcolor);
    }

    @Override
    public void initPlayerStatus()
    {
        this.playerStatus = new PlayerStatus(getDraw(), (int)(RESOLUTION_X*0.1), (int)(RESOLUTION_Y*0.9), (int)(RESOLUTION_X*0.2), (int)(RESOLUTION_Y*0.8));
    }
    @Override
    public void initTable()
    {
        super.table = new Table(getDraw(), RESOLUTION_X, (int)(RESOLUTION_Y*0.65), (int)(RESOLUTION_Y*0.90));
    }
    @Override
    public void initHand()
    {
        this.hand = new Hand(getDraw(), 0, 0, 0);
    }
    @Override
    public void redraw()
    {
        redrawTable();
        redrawEnergy();
    }

    public void autoPlay()
    {
        for (int i = 0; i < Hand.HAND_SIZE; i++)
        {
            if (getHand().getSlot()[i].getCard() != null)
            {
                if (getHand().getSlot()[i].getCard().getEnergy_cost() <= getPlayerStatus().getEnergy())
                {
                    getHand().getSlot()[i].getCard();
                    for (int k = 0; k < Table.SLOTSN; k++)
                    {
                        if (getTable().getSlotPos()[k].getCard() == null)
                        {
                            getTable().getSlotPos()[k].setCard(getHand().getSlot()[i].getCard());
                            getPlayerStatus().removeEnergy(getHand().getSlot()[i].getCard().getEnergy_cost());
                            getHand().getSlot()[i].setCard(null);
                            k = Table.SLOTSN;
                        }
                    }
                }
            }
        }
    }
}
