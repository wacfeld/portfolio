import java.awt.*;
import java.util.ArrayList;
import javax.swing.*;
import java.util.Random;
//import javax.swing.ImageIcon;
//import javax.swing.JFrame;
//import javax.swing.JPanel;

public class NeuronSimulator {
	
	
	
	static boolean foundNull = false;
	
	static JLabel speedLabel = new JLabel("<html><font color=white style='font-size:15'>Set Speed of Simulation: </font></html>");
	static JTextField simSpeed = new JTextField(10);
	//simSpeed.setBounds(0,0,10,100);
	
	static JLabel varianceLabel = new JLabel("<html><font color = white style='font-size:15'>Set randomness factor:</font><input value=hello  /></html>");
	static JTextField simVariance = new JTextField("100",10);
	//simVariance.setBounds(0,0,10,100);
	
	static JFrame app;
	static NeuronSimUI panel;
	static Background back;
	
	
	public static boolean isNumeric(String str)
	{
	    for (char c : str.toCharArray())
	    {
	        if (!Character.isDigit(c)) return false;
	    }
	    return true;
	}
	
	public static void sleep(long millis) {
	    	
		// Creates two values (milliseconds)
		long now = (long) System.currentTimeMillis();   
	    long now2 = now;
	    
	    // Stops program for millis seconds
	    while(now < now2+millis){
	        
	        now = (long) System.currentTimeMillis();
	    }
	}
	
	
	public static void drawLabels(NeuronSimUI panel, JFrame app) {
		
		
		//panel.add(speedLabel);
		//panel.add(simSpeed);
		//panel.add(varianceLabel);
		//panel.add(simVariance);
		
		
	}
	
	public static double genrandom(double lo, double hi) {
    	Random randGenerator = new Random(System.currentTimeMillis());
    	double num = randGenerator.nextDouble();
    	
    	double randomNumber = num * (hi - lo) + lo;
    	
    	return randomNumber;
    }
	
	
	static void removeLabels(JPanel panel,JLabel speedLabel,JTextField simSpeed, JLabel varianceLabel,JTextField simVariance) {
		
		panel.remove(speedLabel);
		panel.remove(simSpeed);
		panel.remove(varianceLabel);
		panel.remove(simVariance);
		
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
        
		// Makes new JFrame, sets icon image, etc.
		app = new JFrame("Neuron Simulator");
		app.setIconImage(new ImageIcon("C:\\Users\\Daniel\\Pictures\\neuroscience.jpg").getImage());
		app.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		app.setUndecorated(true);
		
		// All stuff comes on top of the JPanel, so it must come first
		panel = new NeuronSimUI();
		back = new Background();
		app.add(back);
		app.add(panel);
		
		
		FlowLayout flow = new FlowLayout();
	
		
		panel.setLayout(flow);
		
		//JButton button = new JButton("Click Me");
		//panel.add(button);
		
		
		drawLabels(panel,app);
		app.setSize(1600, 850);
		app.setLocation(0,0);
		app.setVisible(true);
		
		
		
		FlowLayout flow2 = new FlowLayout();
		JLabel label = new JLabel("Randomness factor: ");
		JTextField inputVariance = new JTextField(40);
		
		JLabel nodesOfR = new JLabel("Nodes of Ranvier: ");
		JLabel dendriteD = new JLabel("Length of Dendrite: ");
		JLabel axonL = new JLabel("Length of axon: ");
		JLabel somaL = new JLabel("Length of soma: ");
		
		inputVariance.setText("100");
		
		JFrame app2 = new JFrame();
		app2.setLayout(flow2);
		app2.setSize(1600, 50);
		app2.setLocation(0,850);
		app2.setUndecorated(true);
		app2.setBackground(Color.BLUE);
		
		
		app2.add(nodesOfR);
		app2.add(dendriteD);
		app2.add(axonL);
		app2.add(somaL);
		app2.add(label);
		app2.add(inputVariance);
		
		app2.setVisible(true);
		
		
		ArrayList<String> A = new ArrayList<String>();
		
		int input = (int) ((int) 2.5 + Math.round(Math.random() * 5));

		ArrayList<String> al = new ArrayList<String>();
		ArrayList<String> dd = new ArrayList<String>();
		ArrayList<String> nr = new ArrayList<String>();
		ArrayList<String> sl = new ArrayList<String>();
		
		//neuron.voice();
		
		KeyDetector c_keyDetector = new KeyDetector();
		panel.addMouseListener(c_keyDetector);
		
		//MouseEvent clickListener = new MouseEvent(panel, input, input, input, input, input, input, foundNull);
		panel.addMouseListener(c_keyDetector);
		//int mouseX = clickListener.getX();
		//System.out.println("HEERES " + mouseX);
		
		while(true) {
		
			if(c_keyDetector.b_mousePressed && c_keyDetector.b_mouseEntered && !c_keyDetector.b_activated) {// If the mouse is inside JPanel and pressed and not currently running
				//c_keyDetector.b_activated = true;
				//for(int i = 0; i < 1000; i++) {
					Neuron neuron = new Neuron();
					neuron.setFramePanel(app, panel);
					
					
					neuron.axonLen = (int) Math.round(genrandom(500,1000));
					al.add(String.format("%03d", neuron.axonLen));
					
					neuron.dendriteDist = (int) genrandom(150,neuron.variance/5+150);
					dd.add(String.format("%03d", neuron.dendriteDist));
					
					neuron.nodesOfRanvier = (int)Math.round(neuron.axonLen/10);
					nr.add(String.format("%03d", neuron.nodesOfRanvier));
					
					neuron.somaLen = (int) genrandom(50,neuron.variance/25+50);
					sl.add(String.format("%03d", neuron.somaLen));
					
					
					nodesOfR.setText("Nodes of Ranvier: " + neuron.nodesOfRanvier);
					dendriteD.setText("Length of Dendrite: " + neuron.dendriteDist);
					axonL.setText("Axon Lengcth: " + neuron.axonLen);
					somaL.setText("Soma Length: " + neuron.somaLen);
					
					int inputValue = Integer.valueOf(inputVariance.getText());
									
					if(inputValue > 1000) {
						inputVariance.setText("300");
					}
					if(inputValue < 0) {
						inputVariance.setText("0");
					}
					if(!isNumeric(inputVariance.getText())) {
						inputVariance.setText("100");
					}
					
					neuron.variance = Integer.valueOf(inputVariance.getText());
					
					input = neuron.iap(input);
					
					c_keyDetector.b_mousePressed = false;
					c_keyDetector.b_activated = false;
					
					if(input == -1) {
						System.out.println("Failed");
						
					}
					A.add(String.format("%03d", input));
	
					
					
					System.out.println("Outputs: " + A.toString());
					System.out.println("Dendrit: " + dd.toString());
					System.out.println("Soma Le: " + sl.toString());
					System.out.println("Axon Le: " + al.toString());
					
					System.out.println("None");
					
					c_keyDetector.b_activated = false;
				//}
//				removeLabels(panel, speedLabel, simSpeed, varianceLabel,simVariance);
//				System.out.println("Removed labels");
//				drawLabels(panel,app);
				sleep(1000);
//				System.out.println("Added new labels");
			}
		}
		//}
		
		
		
		
		//input = neuron.iap(input);
		
	}

}
