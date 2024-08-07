package menu;
import edu.princeton.cs.algs4.Draw;
import edu.princeton.cs.algs4.DrawListener;

import java.awt.*;

import javax.swing.JOptionPane;

public class Menu implements DrawListener
{
	private Draw draw;
    private Dimension screen_size;
    private GameScene game;
	private int resolution_x;
	private int resolution_y;

    public Menu ()
    {
		defineScreenSize();
		setResolutionX(getScreenSize().width);
		setResolutionY(getScreenSize().height);
        setDraw(new Draw());
        getDraw().addListener(this);
        getDraw().setCanvasSize(getScreenSize().width, getScreenSize().height);
        getDraw().setXscale(0, getResolutionX());
        getDraw().setYscale(0, getResolutionY());
        getDraw().enableDoubleBuffering();
        getDraw().clear(Color.GREEN);
        getDraw().setPenColor(Color.RED);
        //font size????

        draw.text(getResolutionX()/2, getResolutionY()/2, "click on screen to start", 25);
        draw.show();
    }
    
    public Draw getDraw() {
		return draw;
	}
	public void setDraw(Draw draw) {
		this.draw = draw;
	}
	//resolution

	public int getResolutionX()
	{
		return resolution_x;
	}

	public void setResolutionX(int resolution_x)
	{
		this.resolution_x = resolution_x;
	}

	public int getResolutionY() {
		return resolution_y;
	}

	public void setResolutionY(int resolution_y)
	{
		this.resolution_y = resolution_y;
	}

	//screen size
	public void setScreenSize(Dimension screen_size) 
	{
		this.screen_size = screen_size;
	}
	public Dimension getScreenSize() 
	{
		return this.screen_size;
	}
	public void defineScreenSize() 
    {
    	if(JOptionPane.showConfirmDialog(
                null,
                "Would you like to set the screen size manually?",
                null,
                JOptionPane.YES_NO_OPTION) == 0) 
    	{
    		int x = Integer.parseInt(JOptionPane.showInputDialog(null, "width: "));
    		int y = Integer.parseInt(JOptionPane.showInputDialog(null, "height: "));
    		this.screen_size = new Dimension(x, y);
    	}else 
    	{
    		this.screen_size = Toolkit.getDefaultToolkit().getScreenSize();
    	}
    }
	
    public void mousePressed(double x, double y) 
    {
    	if(game != null) 
    	{
    		game.mousePressed(x, y);
    	}else 
    	{
    		game = new GameScene(getDraw(), getResolutionX(), getResolutionY());
			System.out.println("new game");
    	}
    }
    //main
	public static void main(String[] args) 
	{
		new Menu();
	}
}
