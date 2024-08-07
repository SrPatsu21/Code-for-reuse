package dimension_controler;

import edu.princeton.cs.algs4.Draw;

import java.awt.*;

public class RoundButton extends Button
{
    private int round = 0;
    private Draw draw;
    private Color BACKGROUND;
    public RoundButton()
    {

    }
    public RoundButton(Draw draw, Vec2 start, Vec2 end, int round, Color background)
    {
        super(start, end);
        setDraw(draw);
        this.BACKGROUND = background;
        setRound(round);
    }
    public RoundButton(Draw draw, int x_start, int y_start, int x_end, int y_end, int round, Color background)
    {
        this(draw ,new Vec2(x_start,y_start), new Vec2(x_end, y_end), round, background);
    }

    public Draw getDraw()
    {
        return draw;
    }
    public void setDraw(Draw draw)
    {
        this.draw = draw;
    }
    public int getRound()
    {
        return round;
    }
    public void setRound(int turn_set)
    {
        round = turn_set;
    }
    public void passRound()
    {
        round++;
    }
    //cliente
    public void drawRound(String text)
    {
        getDraw().setPenColor(Color.red);
        getDraw().text(getCenter().getX(), getCenter().getY(), text);
        getDraw().text(getCenter().getX(), getCenter().getY()*0.95, "Round:"+ getRound());
        getDraw().line(getStart().getX(), getStart().getY(), getEnd().getX(), getStart().getY());
        getDraw().line(getStart().getX(), getEnd().getY(), getEnd().getX(), getEnd().getY());
        getDraw().line(getStart().getX(), getStart().getY(), getStart().getX(), getEnd().getY());
        getDraw().line(getEnd().getX(), getStart().getY(), getEnd().getX(), getEnd().getY());
        getDraw().show();
    }
    public void clearRound(Color background)
    {
        getDraw().setPenColor(background);
        getDraw().filledPolygon(new double[]{getStart().getX(), getStart().getX(), getEnd().getX(), getEnd().getX()}, new double[]{getStart().getY(), getEnd().getY(), getEnd().getY(), getStart().getY()});
        getDraw().show();
    }
    public void redrawRound(String text)
    {
        clearRound(BACKGROUND);
        drawRound(text);
    }
}
