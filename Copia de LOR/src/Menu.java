import edu.princeton.cs.algs4.Draw;

import java.awt.*;

public class Menu 
{
    private Draw draw;

    public Menu() 
    {
    	this(Toolkit.getDefaultToolkit().getScreenSize());
    }
    public Menu(Dimension dimension)
    {
        draw = new Draw();
        draw.setXscale(0, (int)dimension.getWidth());
        draw.setYscale(0, (int)dimension.getHeight());
        System.out.println(dimension.getWidth() + "\\" + dimension.getHeight());
        draw.enableDoubleBuffering();
        draw.clear(Color.GREEN);
        draw.setPenColor(Color.LIGHT_GRAY);
        draw.text(10, 5 ,"aaaaaaaaaaaaaa");
        draw.show();
    }
	public static void main(String[] args) 
	{
		new Menu();
	}
}
