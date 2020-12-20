//import javax.swing.JFrame;
import java.awt.Graphics;
import java.awt.Graphics2D;
//import java.awt.Image;
import java.awt.geom.AffineTransform;

import javax.imageio.ImageIO;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

import java.awt.Color;
import java.awt.Font;
import java.awt.image.*;
import java.io.File;
import java.io.IOException;

//import javax.swing.JLabel;
//import javax.swing.ImageIcon;
//import java.awt.BorderLayout;
//import java.lang.Math;

@SuppressWarnings("unused")
public class NeuronSimUI extends JPanel {
	
	private Graphics offg;
	private BufferedImage offi;
	
	private Graphics off2;
	private BufferedImage i2;
	
	private boolean x = true;
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private static final ImageObserver ImageObserver = null;

	public NeuronSimUI() {
		super();
		setBackground(new Color(0,0,0));
		offi = new BufferedImage(1920, 1080, BufferedImage.TYPE_3BYTE_BGR);
		offg = offi.createGraphics();
		
		i2 = new BufferedImage(1920, 1080, BufferedImage.TYPE_3BYTE_BGR);
		off2 = offi.createGraphics();
		
	}
	
	public void sleep(long millis) {
		long now = (long) System.currentTimeMillis();   
	    long now2 = now;
	    
	    // Stops program for millis seconds
	    while(now < now2+millis){
	        
	        now = (long) System.currentTimeMillis();
	    }
	}
	
	public void drawBack(Graphics g) {
		int width = getWidth();
		int height = getHeight();
		super.paintComponent(off2);
		
		//System.out.println("Hi");
		
		Font font = new Font(Font.SERIF, 0, 30);
		Font font2 = new Font("EB Garamond", 0, 17);
		off2.setFont(font);
		
		
		// Draws the center neuron
		off2.setColor(Color.GREEN);
		off2.fillRect(510, 450, 250, 5);
		off2.drawString("Dendrite", 575, 490);
		
		off2.setColor(Color.RED);
		off2.fillRect(800, 450, 500, 5);
		off2.drawString("Axon",1050,490);
		
		off2.setColor(Color.ORANGE);
		off2.fillRect(840, 440, 20, 20);
		off2.drawString("Hillock", 870, 490);
		
		off2.setColor(Color.BLUE);
		off2.fillArc(750, 400, 100, 100, 0, 360);
		off2.drawString("Soma", 765, 530);
		
		off2.setColor(Color.WHITE);
		off2.fillRect(1300, 440, 26, 26);
		off2.drawString("Terminal",1260,500);
		
		
		off2.setColor(new Color(100,100,100));// Left neuron color gray
		
		off2.fillRect(150, 450, 350, 5);// Left neuron Axon
		
		off2.fillArc(100, 400, 100, 100, 0, 360);// Left neuron Soma
		
		off2.fillRect(495, 440, 26, 26);// Left neuron Terminal
		
		off2.fillRect(-1, 450, 350, 5);
		
		off2.fillRect(190, 440, 20, 20);
		
		
		off2.fillRect(1326, 450, 350, 5);
		
		off2.setColor(Color.WHITE);
		off2.setFont(font2);
		//System.out.println("dsj");
		
		//g.drawImage(i2, 0, 0, null);
		//offg.clearRect(0,0,getWidth(),getHeight());
		
	}
	
	
	private void drawMultipleLine(Graphics g, String s, int x, int y )
	{
		    for (String line : s.split("\n"))
		        g.drawString(line, x, y += g.getFontMetrics().getHeight());
		
	}
	private static BufferedImage scale(BufferedImage sbi, int imageType, int dWidth, int dHeight, double fWidth, double fHeight) {
	    BufferedImage dbi = null;
	    if(sbi != null) {
	        dbi = new BufferedImage(dWidth, dHeight, imageType);
	        Graphics2D g = dbi.createGraphics();
	        AffineTransform at = AffineTransform.getScaleInstance(fWidth, fHeight);
	        g.drawRenderedImage(sbi, at);
	    }
	    return dbi;
	}
	public void paintComponent(Graphics g) {
		int width = getWidth();
		int height = getHeight();
		
		super.paintComponent(g);
		
		drawBack(g);
		
		//g.setBackground(Color.BLACK);

		Font font = new Font(Font.SERIF, 0, 30);
		Font font2 = new Font("EB Garamond", 0, 17);
		offg.setFont(font);
		
		
		// Draws the center neuron
		offg.setColor(Color.GREEN);
		offg.fillRect(510, 450, 250, 5);
		offg.drawString("Dendrite", 575, 490);
		
		offg.setColor(Color.RED);
		offg.fillRect(800, 450, 500, 5);
		offg.drawString("Axon",1050,490);
		
		offg.setColor(Color.ORANGE);
		offg.fillRect(840, 440, 20, 20);
		offg.drawString("Hillock", 870, 490);
		
		offg.setColor(Color.BLUE);
		offg.fillArc(750, 400, 100, 100, 0, 360);
		offg.drawString("Soma", 765, 530);
		
		offg.setColor(Color.WHITE);
		offg.fillRect(1300, 440, 26, 26);
		offg.drawString("Terminal",1260,500);
		
		
		offg.setColor(new Color(100,100,100));// Left neuron color gray
		
		offg.fillRect(150, 450, 350, 5);// Left neuron Axon
		
		offg.fillArc(100, 400, 100, 100, 0, 360);// Left neuron Soma
		
		offg.fillRect(495, 440, 26, 26);// Left neuron Terminal
		
		offg.fillRect(-1, 450, 350, 5);
		
		offg.fillRect(190, 440, 20, 20);
		
		
		offg.fillRect(1326, 450, 350, 5);
		
		offg.setColor(Color.WHITE);
		offg.setFont(font2);
		//g.drawString("Set randomness factor", 550, 20);
		
		NeuronSimulator.removeLabels(NeuronSimulator.panel,NeuronSimulator.speedLabel,NeuronSimulator.simSpeed, NeuronSimulator.varianceLabel,NeuronSimulator.simVariance);
		NeuronSimulator.drawLabels(NeuronSimulator.panel,NeuronSimulator.app);
		
		
		g.drawImage(offi, 0, 0, null);
		//sleep(10);
		//offg.clearRect(0,0,getWidth(),getHeight());
//sleep(100);
		
		//offg.setColor(Color.WHITE);
	}
	
}