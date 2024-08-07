package players;

import cards.Card;
import dimension_controler.Button;
import dimension_controler.Vec2;

public class Slot {
	private Button button;
	private Card card;

	public Slot()
	{
		
	}
	public Slot(int x0, int y0, int x1, int y1)
	{
		this(new Vec2(x0, y0), new Vec2(x1, y1));
	}
	public Slot(Vec2 start, Vec2 end)
	{
		setButton(new Button(start, end));
	}
	public Button getButton()
	{
		return button;
	}
	public void setButton(Button button)
	{
		this.button = button;
	}
	public void setCard(Card card)
	{
		this.card = card;
	}
	public Card getCard() 
	{
		return this.card;
	}
}
