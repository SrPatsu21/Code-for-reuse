package players;

import cards.Card;
import cards.CardGenerator;
import dimension_controler.Button;
import dimension_controler.Vec2;
import edu.princeton.cs.algs4.Draw;

import java.awt.*;

public class Hand
{
    public static final int HAND_SIZE = 10;
    private Slot[] slot = new Slot [HAND_SIZE];
    private Draw draw;
    private Button hand_pos;
    private int cards_on_hand = 0;
    public final int COLS_SIZE;
    public final int MARGE;
    public static final int COLSN = 20;
    private final CardGenerator CARD_GENERATOR = new CardGenerator();

    public Hand(Draw draw,int resolution_x, int y0, int y1)
    {
        COLS_SIZE = resolution_x/COLSN;
        MARGE = (COLS_SIZE*COLSN/2) - (HAND_SIZE*COLS_SIZE/2+1);
        setDraw(draw);
        defineHandPos(resolution_x, y0, y1);
        defineSlots();
    }

    public Draw getDraw()
    {
        return draw;
    }
    public void setDraw(Draw draw)
    {
        this.draw = draw;
    }
    public Slot[] getSlot()
    {
        return slot;
    }
    public Button getHand_pos()
    {
        return hand_pos;
    }
    public int getCardsOnHand()
    {
        return cards_on_hand;
    }
    public void setSlot(Slot[] slot)
    {
        this.slot = slot;
    }
    public void setSlot(int i, Slot slot)
    {
        this.slot[i] = slot;
    }
    public void setHand_pos(Button hand_pos)
    {
        this.hand_pos = hand_pos;
    }
    public void setCardsOnHand(int cards_on_hand)
    {
        this.cards_on_hand = cards_on_hand;
    }
    private void defineHandPos(int resolution_x, int y0, int y1)
    {
        this.hand_pos = new Button(new Vec2((int)(resolution_x*0.1), y0), new Vec2((int)(resolution_x*0.9), y1));
    }
    private void defineSlots()
    {
        for (int i = 0; i < HAND_SIZE; i++)
        {
            this.slot[i] = new Slot(
                    new Vec2(MARGE+(i*COLS_SIZE), getHand_pos().getStart().getY()),
                    new Vec2(MARGE+((i+1)*COLS_SIZE), getHand_pos().getEnd().getY())
            );
        }
    }
    public void verifySlots()
    {
        int k = 0;
        for (int i = 0; i > HAND_SIZE; i++)
        {
            if (getSlot()[i] != null)
            {
                if (getSlot()[i].getCard() != null)
                {
                    k++;
                }
            }
        }
        setCardsOnHand(k);
    }
    public void addCard()
    {
        if (cards_on_hand < HAND_SIZE)
        {
            for (int i = 0; i < HAND_SIZE; i++)
            {
                if (getSlot()[i] != null)
                {
                    if (getSlot()[i].getCard() == null)
                    {
                        this.slot[i].setCard(CARD_GENERATOR.takeRandCard());
                        this.cards_on_hand++;
                        i = HAND_SIZE;
                    }
                }
            }
        }
    }
    public void removeCard(int i)
    {
        getSlot()[i].setCard(null);
        this.cards_on_hand--;
    }
    public void removeCard(Card card)
    {
        for (int i = 0; i < HAND_SIZE; i++)
        {
            if (getSlot()[i] != null)
            {
                if (getSlot()[i].getCard() == card)
                {
                    getSlot()[i].setCard(null);
                    this.cards_on_hand--;
                    i=HAND_SIZE;
                }
            }
        }
    }
    //cliente
    public void clearHand(Color background)
    {
        getDraw().setPenColor(background);
        getDraw().filledPolygon(new double[]{getHand_pos().getStart().getX(), getHand_pos().getStart().getX(), getHand_pos().getEnd().getX(), getHand_pos().getEnd().getX()}, new double[]{getHand_pos().getStart().getY(), getHand_pos().getEnd().getY(), getHand_pos().getEnd().getY(), getHand_pos().getStart().getY()});
        getDraw().show();
    }
    public void drawCards()
    {
        for (int i = 0; i < HAND_SIZE; i++)
        {
            if(getSlot()[i] != null)
            {
                if(getSlot()[i].getCard() != null)
                {
                    getSlot()[i].getCard().drawCard(getDraw(), getSlot()[i].getButton().getStart(), getSlot()[i].getButton().getEnd());
                }
            }
        }
        getDraw().show();
    }
    public void redrawOneCard(Slot slot)
    {
        slot.getCard().drawCard(getDraw(), slot.getButton().getStart(), slot.getButton().getEnd());
        getDraw().show();
    }
    public void redrawOneCard(Slot slot, Color background)
    {
        slot.getCard().drawCard(getDraw(), slot.getButton().getStart(), slot.getButton().getEnd(), background);
        getDraw().show();
    }

    public void drawSlots(Color color)
    {
        getDraw().setPenColor(color);
        for(int pos = 0; pos < HAND_SIZE; pos++) {
            // x1, y1, x2, y2
            getDraw().line(MARGE+(pos*COLS_SIZE), getHand_pos().getStart().getY(), MARGE+(pos*COLS_SIZE), getHand_pos().getEnd().getY());
            getDraw().line(MARGE+((pos+1)*COLS_SIZE), getHand_pos().getStart().getY(), MARGE+((pos+1)*COLS_SIZE), getHand_pos().getEnd().getY());
            getDraw().line(MARGE+(pos*COLS_SIZE), getHand_pos().getStart().getY(), MARGE+((pos+1)*COLS_SIZE), getHand_pos().getStart().getY());
            getDraw().line(MARGE+(pos*COLS_SIZE), getHand_pos().getEnd().getY(), MARGE+((pos+1)*COLS_SIZE), getHand_pos().getEnd().getY());
        }
        getDraw().show();
    }

    public void drawHand(Color slots, Color background)
    {
        clearHand(background);
        drawSlots(slots);
        drawCards();
        getDraw().show();
    }
}
