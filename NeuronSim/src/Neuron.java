import java.lang.Math;
import java.awt.Graphics;

import javax.sound.sampled.LineUnavailableException;
import javax.swing.JFrame;
import java.awt.Color;

import java.util.Random;

@SuppressWarnings("serial")
public class Neuron {
    int axonLen;
    int schwannNum;
    
    int mp = -70;
    int dendriteDist;
    int nodesOfRanvier;
    public int variance = 300;

    int somaLen;
    
    // To paint things onto the canvas, one by one
    JFrame m_frame;
    NeuronSimUI m_panel;
    Graphics g;
    
    // Constructor
    public Neuron() {
        //super();
    }
    
    public static double genRandom(double lo, double hi) {
    	Random randGenerator = new Random(System.currentTimeMillis());
    	double num = randGenerator.nextDouble();
    	
    	double randomNumber = num * (hi - lo) + lo;
    	
    	return randomNumber;
    }
    
    
    public void voice() {
    	
    	SoundDetector sDetector = new SoundDetector();
    	
    	try {
			sDetector.checkForSound();
		} catch (LineUnavailableException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    }
    
    
    public void setFramePanel(JFrame f,NeuronSimUI p)
    {
    	m_frame = f;
    	m_panel = p;
    	g = m_frame.getGraphics();
    }
    
    
    public void sleep(long millis) {
    	
    	// Creates two values (milliseconds)
    	long now = (long) System.currentTimeMillis();   
        long now2 = now;
        
        // Stops program for millis seconds
        while(now < now2+millis){
            
            now = (long) System.currentTimeMillis();
        }
    }
    
    
    
    // Diffusion of Sodium
    public void diffuse(int time, int power) {

        //System.out.println("Diffusing...");

        //Values for the ideal resting neuron
        // Sodium (Na+) concentration (per micrometer cubed) on outside and inside
        int naOnOutside = 70;
        int naOnInside = 0;
        
        // Same with Potassium (K+)
        //int kOnOutside = 0;
        //int kOnInside = 100;
        
        // Power is how many gates open
        for(int t = 0; t < time * 5; t++) {
        	
        	
            float pressure = (float) (naOnOutside - naOnInside)/3;// The difference in the concentration of sodium

            int decider = (int) genRandom(0,1);

            // Gives some na+ to the inside
            if(decider == 1) {
            	int randNum = (int) (genRandom(0,variance/20));
                naOnOutside -= power * (pressure/2 + randNum);
                naOnInside  += power * (pressure/2 + randNum);
            }

            if(decider == 0) {
            	int randNum = (int) (genRandom(0,variance/20));
            	naOnOutside -= power * (pressure/2 - randNum);
            	naOnInside  += power * (pressure/2 - randNum);
            }
            mp = naOnInside - naOnOutside;
        }



    }
    
    
    
    
    // Initiates action potential
    public int iap(int input) {
    	
    	
    	 if (input < 0) {
    		 return -1;
    	 }
    	
    	
        System.out.println("Initiating Action Potential...");
sleep(500);
        
        
        
        // Declaring variables
        int dist = somaLen + dendriteDist;
        int distTraveled = 0;
        //int time = 0;
        boolean mf = false;

        //Phase 1: Dendrite and soma
        System.out.println("Reached Dendrite and Soma");
        diffuse(3,input);// Diffuses for 1 millisecond
        if(mp > -56) {
        	
        	distTraveled += 5;
        	mp = -70;

        	while(mf == false && distTraveled < dist) {
        		diffuse(5,3);
        		if(mp > -56) {
        			distTraveled+=5;
        			
//        			for(int z = 0; z < 10; z++) {
//        				Graphics g = m_frame.getGraphics();
//            			g.setColor(Color.WHITE);
//            			m_panel.paintComponent(g);
//            			
//            			g.fillRect((int)(500 + distTraveled*1.65), 380, 2, 155);
//            			
            			sleep(1);
//        			}

        			//for(int z = 0; z < 1; z++) {
            			m_panel.paintComponent(g);
            			g.setColor(Color.WHITE);
            			g.fillRect((int)(500 + distTraveled*1.4), 380, 2, 155);
        			//}
        			sleep(50);
        			mp = -70;
        		}
        		else {mf = true;}

        	}
        }
        else {mf = true;}

//        if(mf = true) {
//        	System.out.println("Failed to initiate");
//        	return -1;
//        }
//EFfective Java, cryptograpahy engineering, the art of computer programming by donald Knuth, 
//public protected static private void if else final volatile synchronized, try, catch, throw, throws, finally, extends, true, false, implements, class, interface, abstract, enum, int, double, char, long, short, byte, boolean, float, null, import, super, new, return, while, for, do, package, break, case, assert, switch, const, continue, default, goto, instanceof, native, strictfp, this, transient
        		
        
        // Phase 2: Axon Hillock/Axon
        // Resets distances for the axon
        System.out.println("Reached axon");
        dist = axonLen;
        distTraveled = 0;
        
        int distToNode = 10;
        int nodesToGo = nodesOfRanvier;
        
        //int ind = 1;
        
        
        diffuse(5,12);
        if(mp > -56) {
        	dist += 10;
        	
        	sleep(75);
        	mp = -70;
        	
//System.out.println("In front of WHILE");

        	while(nodesToGo > 0) {
        		while(distToNode > 0 && mf == false) {
        			distToNode-=1;
        			mp -= genRandom(0,variance/50);
        			
        			//for(int z = 0; z < 20; z++) {
        				
            			g.setColor(Color.WHITE);
            			m_panel.paintComponent(g);
            			
            			g.fillRect( 830 + (1 + nodesOfRanvier - nodesToGo) * (11 - distToNode) * 45, 380, 2, 155);

sleep(50);
        				
        			//}a
        			
        			
        		}
        		if(mp < -56) {
        			mf = true;
        		}
        		else {
        			diffuse(5,15);
        			if(!(mp > -56)) {
        				mf = true;
        			}
        		}
        		
        		nodesToGo -=1;
        	}
        	
        	sleep(500);
        	
        	//Graphics g = m_frame.getGraphics();
        	//m_panel.paintComponent(g);
        	
//        	if(mf == true) {
//        		System.out.println("Failed to initiate");
//        		return -1;
//        	}
        	// Phase 3: Axon terminal
        	System.out.println("Axon terminal");
        	mp = -70;
        	diffuse(5,3);
        	if(mp > -56) {
        		mp = -70;
        		
        		return (int) ((int) 2.5 + Math.round(genRandom(0,variance/20)));
        	}
        	else {
        		mf = true;
        	}
        	
        }
        
        sleep(500);
        
        if(mf == false) {
        	return (int) ((int) 2.5 + Math.round(genRandom(0,variance/20)));
        }
        if(mf == true) {
        	
			g.setColor(Color.WHITE);
			m_panel.paintComponent(g);
			g.setColor(Color.RED);
        	g.fillRect( 0, 0, 200, 155);
//sleep(500);
        	//m_panel.paintComponent(g);
        	mf = false;
        	return 8;
        }
        return -2;

    }

}
