package cards;

import dimension_controler.Vec2;
import edu.princeton.cs.algs4.Draw;

import java.awt.*;

public class Card
{
	private final int id;
	private byte type;
	protected String description;
	protected byte full_life;
	protected byte energy_cost;
	//status
	protected byte life;
	protected byte damage;
	//buffs
	protected byte damage_buff;
	protected byte life_buff;
	protected byte damage_buff_turns;
	protected byte life_buff_turns;

	public Card(int id, byte type)
	{
		this.id = id;
		this.type = type;
	}
	public Card(int id, byte type, byte full_life, byte life, byte damage, byte energy_cost, String description)
	{
		this(id, type);
		setFullLife(full_life);
		setLife(life);
		setDamage(damage);
		setEnergy_cost(energy_cost);
		setDescription(description);
	}

	public byte getFullLife()
	{
		return life;
	}
	public void setFullLife(byte full_life)
	{
		this.full_life = full_life;
	}
	public byte getLife()
	{
		return life;
	}
	public void setLife(byte life)
	{
		this.life = (byte)Math.max(0, life);
	}
	public byte getDamage()
	{
		return damage;
	}
	public void setDamage(byte damage)
	{
		this.damage = (byte)Math.max(0, damage);
	}
	public String getDescription()
	{
		return description;
	}
	public void setDescription(String description)
	{
		this.description = description;
	}
	public int getId()
	{
		return id;
	}
	public byte getType()
	{
		return type;
	}
	public void setType(byte type)
	{
		this.type = type;
	}
	public byte getEnergy_cost()
	{
		return energy_cost;
	}
	public void setEnergy_cost(byte energy_cost)
	{
		this.energy_cost = energy_cost;
	}

	//buff
	public void buffDamage(byte turns, byte buff)
	{
		this.damage_buff += buff;
		this.damage_buff_turns += turns;
	}
	public void buffLife(byte turns, byte buff)
	{
		this.life_buff += buff;
		this.life_buff_turns += turns;
	}
	public void dbuffDamage(byte turns, byte buff)
	{
		this.damage_buff -= buff*-1;
		this.damage_buff_turns -= turns;
	}
	public void dbuffLife(byte turns, byte buff)
	{
		this.life_buff -= buff;
		this.life_buff_turns -= turns;
	}
	public void clearLifeBuff()
	{
		this.life_buff = 0;
		this.life_buff_turns = 0;
	}
	public void clearDamageBuff()
	{
		this.damage_buff = 0;
		this.damage_buff_turns = 0;
	}
	public void clearBuff()
	{
		clearLifeBuff();
		clearDamageBuff();
	}

	public void passTurn() {
		if(this.life_buff_turns != 0) {
			if(this.life_buff_turns < 0) {
				this.life_buff_turns++;
			}else {
				this.life_buff_turns--;
			}
			if(this.life_buff_turns == 0) {
				clearLifeBuff();
			}
		}
		if(this.damage_buff_turns != 0) {
			if(this.damage_buff_turns < 0) {
				this.damage_buff_turns++;
			}else {
				this.damage_buff_turns--;
			}
			if(this.damage_buff_turns == 0) {
				clearDamageBuff();
			}
		}
	}

	//attack and defense
	public byte getActualDamage()
	{
		return (byte)(this.damage+this.damage_buff);
	}

	public byte getActualLife()
	{
		return (byte)(this.life+this.life_buff);
	}

	//receive damage
	public byte receiveDamage(int damage) {

		if(damage < this.life_buff) {
			this.life_buff -= damage;
		}else {
			this.life -= damage - this.life_buff;
		}
		if(this.life + this.life_buff < damage)
		{
			this.kill();
			return 0;
		}else
		{
			return 1;
		}
	}

	//kill
	public void kill()
	{
	}

	//draw cards
	public void  drawCard(Draw draw, Vec2 start, Vec2 end)
	{
		this.drawCard(draw, start, end, Color.WHITE);
	}
	public void  drawCard(Draw draw, Vec2 start, Vec2 end, Color background)
	{
		int diffx = end.getX() - start.getX();
		int diffy = end.getY() - start.getY();
		//backgrund
		draw.setPenColor(background);
		draw.filledPolygon(new double[]{start.getX(), start.getX(), end.getX(), end.getX()}, new double[]{start.getY(), end.getY(), end.getY(), start.getY()});
		//line
		draw.setPenColor(Color.BLACK);
		draw.line(start.getX(), start.getY(), end.getX(),  start.getY());
		draw.line(start.getX(), end.getY(), end.getX(),  end.getY());
		draw.line(start.getX(), start.getY(), start.getX(),  end.getY());
		draw.line(end.getX(), start.getY(), end.getX(),  end.getY());
		//text
		String [] split = getDescription().split("\n");
		draw.text(start.getX()+ diffx*0.5, start.getY()+diffy*0.57, split[0]);
		draw.text(start.getX()+ diffx*0.5, start.getY()+diffy*0.43, split[1]);
		//life
		draw.setPenColor(Color.RED);
		draw.text(start.getX()+ diffx*0.9, end.getY()-diffy*0.1, String.valueOf((int)getActualLife()));
		//damage
		draw.setPenColor(Color.GREEN);
		draw.text(start.getX()+ diffx*0.1, end.getY()-diffy*0.1, String.valueOf((int)getActualDamage()));
		//energy cost
		draw.setPenColor(Color.ORANGE);
		draw.text(start.getX()+ diffx*0.5, end.getY()-diffy*0.9, "cost:"+String.valueOf((int)getEnergy_cost()));
	}
}
