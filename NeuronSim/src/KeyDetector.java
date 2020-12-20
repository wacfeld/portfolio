import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class KeyDetector implements MouseListener {
	
	boolean b_mouseEntered = false;
	boolean b_mousePressed = false;
	boolean b_activated = false;
	
	public void mousePressed(MouseEvent e) {
		b_mousePressed = true;
	}

	public void mouseReleased(MouseEvent e) {
		//saySomething("Mouse released; # of clicks: " + e.getClickCount(), e);
	}

	public void mouseEntered(MouseEvent e) {
		b_mouseEntered = true;
	}

	public void mouseExited(MouseEvent e) {
		b_mouseEntered = false;
	}

	public void mouseClicked(MouseEvent e) {
		//saySomething("Mouse clicked (# of clicks: " + e.getClickCount() + ")", e);
		
	}

	
}
