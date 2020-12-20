import javax.swing.JFrame;
import java.awt.Graphics;
import javax.swing.JPanel;
import java.awt.Color;
import javax.swing.JLabel;
import javax.swing.ImageIcon;
import java.awt.BorderLayout;
import java.awt.Font;

public class StartFrame extends JPanel {
    public StartFrame() {                      
        super();
        setBackground(new Color(30,30,30));
    }

    public void paintComponent(Graphics g) 
    {
        int width = getWidth();    
        int height = getHeight();      

        super.paintComponent(g);    


        // Drawing code goes here
        Font font = new Font(Font.SERIF, Font.BOLD, 40);
        g.setColor(new Color(0,0,130));
        g.setFont(font);
        g.drawString("Neuron Simulator 1.0", 130, 180);
        
        g.setColor(new Color(100,100,100));
        Font font2 = new Font(Font.SERIF, Font.ITALIC, 20);
        g.setFont(font2);
        g.drawString("Made by Wacfeld Inc.", 220, 205);
        
        
        
        //g.dispose();
    }

   

}