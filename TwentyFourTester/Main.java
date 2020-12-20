import java.util.Scanner;
import java.util.ArrayList;
import java.lang.Math;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner reader = new Scanner(System.in);  // Reading from System.in
		
		
		ArrayList<Float> inputs = new ArrayList<Float>();
		
		for(int i=0;i<4;i++) {
			System.out.println("Enter a number between 1 and 13 (inclusive): ");
			float n = reader.nextFloat();
			if(n < 1 || n > 13 || Math.round(n) - n != 0) {
				System.out.println("Invalid number. Please try again");
				i--;
				continue;
			}
			
			else {
				inputs.add(n);
			}
			
		}
		
		int in0 = (int) Math.round(inputs.get(0));
		int in1 = (int) Math.round(inputs.get(1));
		int in2 = (int) Math.round(inputs.get(2));
		int in3 = (int) Math.round(inputs.get(3));
		
		Tester tester = new Tester(in0,in1,in2,in3);
		tester.permuteArray(tester.numbers, 0, 3);
		//Boolean trueFalse = tester.sortNumbers();
		
		//System.out.println("Numbers is " + tester.numbers);
	}

}
