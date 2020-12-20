import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;

import javax.swing.JPanel;

public class Background extends JPanel {
	
	public Background()
    {
        super();
        setBackground(Color.BLACK);
    }
	
	
	
	
	public void paintComponent(Graphics g)
    {
        int width = getWidth();
        int height = getHeight();

        super.paintComponent(g);

        // Drawing code goes here
        Font font = new Font(Font.SERIF, 0, 30);
		Font font2 = new Font("EB Garamond", 0, 17);
		g.setFont(font);
		
		
		// Draws the center neuron
		g.setColor(Color.GREEN);
		g.fillRect(510, 450, 250, 5);
		g.drawString("Dendrite", 575, 490);
		
		g.setColor(Color.RED);
		g.fillRect(800, 450, 500, 5);
		g.drawString("Axon",1050,490);
		
		g.setColor(Color.ORANGE);
		g.fillRect(840, 440, 20, 20);
		g.drawString("Hillock", 870, 490);
		
		g.setColor(Color.BLUE);
		g.fillArc(750, 400, 100, 100, 0, 360);
		g.drawString("Soma", 765, 530);
		
		g.setColor(Color.WHITE);
		g.fillRect(1300, 440, 26, 26);
		g.drawString("Terminal",1260,500);
		
		
		g.setColor(new Color(100,100,100));// Left neuron color gray
		
		g.fillRect(150, 450, 350, 5);// Left neuron Axon
		
		g.fillArc(100, 400, 100, 100, 0, 360);// Left neuron Soma
		
		g.fillRect(495, 440, 26, 26);// Left neuron Terminal
		
		g.fillRect(-1, 450, 350, 5);
		
		g.fillRect(190, 440, 20, 20);
		
		
		g.fillRect(1326, 450, 350, 5);
		
		g.setColor(Color.WHITE);
		g.setFont(font2);
    }
}
