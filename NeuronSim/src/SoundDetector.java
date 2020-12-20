import java.io.ByteArrayOutputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

import javax.sound.sampled.AudioFormat;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.DataLine;
import javax.sound.sampled.Line;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.Mixer;
import javax.sound.sampled.TargetDataLine;


public class SoundDetector {
	AudioFormat m_format ;
	TargetDataLine m_microphone;
	
	public SoundDetector()
	{
	   m_format = new AudioFormat(8000.0f, 16, 1, true, true);
	   try{
            m_microphone = AudioSystem.getTargetDataLine(m_format);
	   }
	   catch(Exception e)
	   {
		   
	   }
	}
	
	public double checkForSound() throws LineUnavailableException {
		
		Mixer.Info[] mixerInfos = AudioSystem.getMixerInfo();

		for (Mixer.Info info: mixerInfos) {

			Mixer m = AudioSystem.getMixer(info);

			Line.Info[] lineInfos = m.getSourceLineInfo();

			for (Line.Info lineInfo:lineInfos){
				System.out.println (info.getName()+"---"+lineInfo);
				Line line = m.getLine(lineInfo);
				System.out.println("\t-----"+line);
			}

			lineInfos = m.getTargetLineInfo();
			
			for (Line.Info lineInfo:lineInfos){
				System.out.println (m+"---"+lineInfo);
				Line line = m.getLine(lineInfo);
				System.out.println("\t-----"+line);
			}

		}
		
		
		
		TargetDataLine line = null;
		DataLine.Info info = new DataLine.Info(TargetDataLine.class,
		                m_format); // format is an AudioFormat object
		if (!AudioSystem.isLineSupported(info)) {
		    // Handle the error ...

		}
		// Obtain and open the line.
		try {
		    line = (TargetDataLine) AudioSystem.getLine(info);
		    line.open(m_format);
		} catch (LineUnavailableException ex) {
		    // Handle the error ...
		}

		// Assume that the TargetDataLine, line, has already
		// been obtained and opened.
		FileOutputStream out = null;
		try {
			out = new FileOutputStream("mysound");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		int numBytesRead;
		byte[] data = new byte[line.getBufferSize() / 5];

		// Begin audio capture.
		line.start();
		
		boolean stopped = true;
		int Loop=1600;
		// Here, stopped is a global boolean set by another thread.
		while (Loop>0) {
			Loop = Loop -1;
		    // Read the next chunk of data from the TargetDataLine.
		    numBytesRead =  line.read(data, 0, data.length);
		    // Save this chunk of data.
		    try {
				out.write(data, 0, numBytesRead);
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		try {
			out.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return 0;
	}
	
}
