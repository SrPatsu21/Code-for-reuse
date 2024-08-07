package players;

import java.awt.Color;

import cards.CardGenerator;
import dimension_controler.Button;
import edu.princeton.cs.algs4.Draw;

public class Table 
{
    private Draw draw;
    public static final int SLOTSN = 6;
    public static final int COLSN = 16;
    public final int COLS_SIZE;
    public final int MARGE;
    private Slot [] slot_pos = new Slot[SLOTSN];
	private Button button;

	public Table(Draw draw, int resolution_x, int y0, int y1)
	{
		this(draw, resolution_x);
		setButton(new Button(MARGE, y0, MARGE+COLS_SIZE*(SLOTSN), y1));
		defineSlotPos();
	}

	public Table(Draw draw, int resolution_x)
	{
		setDraw(draw);
		COLS_SIZE = resolution_x/COLSN;
		MARGE = (COLS_SIZE*COLSN/2) - (SLOTSN*COLS_SIZE/2+1);
	}

	//getter setter
    public Draw getDraw() {
		return draw;
	}

	public void setDraw(Draw draw) {
		this.draw = draw;
	}

	public Slot[] getSlotPos() {
		return slot_pos;
	}

	public void setSlot_pos(Slot[] slot_pos) {
		this.slot_pos = slot_pos;
	}

	public Button getButton() {
		return button;
	}

	public void setButton(Button button) {
		this.button = button;
	}

	//position on map
	private void defineSlotPos()
	{
		for(int pos = 0; pos < SLOTSN; pos++) {
			getSlotPos()[pos] = new Slot(MARGE+(pos*COLS_SIZE), getButton().getStart().getY(), MARGE+((pos+1)*COLS_SIZE), getButton().getEnd().getY());
		}
	}
	//remove dead
	public void removeDeadCards()
	{
		for (int i = 0; i < SLOTSN; i++)
		{
			if (getSlotPos()[i].getCard() != null)
			{
				if (getSlotPos()[i].getCard().getLife() <= 0)
				{
					getSlotPos()[i].setCard(null);
				}
			}
		}
	}
	//client
	public void clearTable(Color background)
	{
		getDraw().setPenColor(background);
		getDraw().filledPolygon(new double[]{getButton().getStart().getX(), getButton().getStart().getX(), getButton().getEnd().getX(), getButton().getEnd().getX()}, new double[]{getButton().getStart().getY(), getButton().getEnd().getY(), getButton().getEnd().getY(), getButton().getStart().getY()});
		getDraw().show();
	}

	public void drawSlot(Color color)
    {
		getDraw().setPenColor(color);
		for(int pos = 0; pos < SLOTSN; pos++)
		{
			// x1, y1, x2, y2
			getDraw().line(MARGE+(pos*COLS_SIZE), getButton().getStart().getY(), MARGE+(pos*COLS_SIZE), getButton().getEnd().getY());
			getDraw().line(MARGE+((pos+1)*COLS_SIZE), getButton().getStart().getY(), MARGE+((pos+1)*COLS_SIZE), getButton().getEnd().getY());
			getDraw().line(MARGE+(pos*COLS_SIZE), getButton().getStart().getY(), MARGE+((pos+1)*COLS_SIZE), getButton().getStart().getY());
			getDraw().line(MARGE+(pos*COLS_SIZE), getButton().getEnd().getY(), MARGE+((pos+1)*COLS_SIZE), getButton().getEnd().getY());
		}
		getDraw().show();
    }
	public void drawCards()
	{
		for (int i = 0; i < SLOTSN; i++)
		{
			if(getSlotPos()[i] != null)
			{
				if(getSlotPos()[i].getCard() != null)
				{
					getSlotPos()[i].getCard().drawCard(getDraw(), getSlotPos()[i].getButton().getStart(), getSlotPos()[i].getButton().getEnd());
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

	public void drawTable(Color background, Color lines)
	{
		clearTable(background);
		drawSlot(lines);
		drawCards();
	}
}