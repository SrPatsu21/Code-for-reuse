package dimension_controler;

public class Button
{
    private Vec2 start;
    private Vec2 end;

    public Button()
    {

    }
    public Button(Vec2 start, Vec2 end)
    {
        setStart(start);
        setEnd(end);
    }
    public Button(int x_start, int y_start, int x_end, int y_end)
    {
        this(new Vec2(x_start,y_start), new Vec2(x_end, y_end));
    }
    public Vec2 getStart()
    {
        return start;
    }
    public void setStart(Vec2 start)
    {
        this.start = start;
    }
    public Vec2 getEnd()
    {
        return end;
    }
    public void setEnd(Vec2 end)
    {
        this.end = end;
    }
    public boolean isInside(int x, int y)
    {
        return this.isInside((double)x, (double)y);
    }
    public boolean isInside(double x, double y)
    {
        if ((getStart().getX() < x && getEnd().getX() > x) && (getStart().getY() < y && getEnd().getY() > y))
        {
            return true;
        }else
        {
            return false;
        }
    }
    public Vec2 getCenter()
    {
        return new Vec2(getStart().getX()+(getEnd().getX()-getStart().getX())/2, getStart().getY()+(getEnd().getY()-getStart().getY())/2);
    }
}
