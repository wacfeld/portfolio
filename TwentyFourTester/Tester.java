import java.util.ArrayList;

public class Tester {

	
	String stringRes = "";
	
	Integer TwentyFour = 24;
	ArrayList<Integer> referenceNumbers = new ArrayList<Integer>(4);
	ArrayList<Integer> numbers = referenceNumbers;
	
	public Tester(Integer n1, Integer n2, Integer n3, Integer n4) {
		referenceNumbers.add(n1);
		referenceNumbers.add(n2);
		referenceNumbers.add(n3);
		referenceNumbers.add(n4);
	}
	
	String[] operators = {
		"+",
		"-",
		"*",
		"/"
	};
	
	
	private void switchValues(ArrayList<Integer> arrayToSwitch, Integer int1, Integer int2) {
		
		Integer placeHolder;
		
		placeHolder =  arrayToSwitch.get(int1);
 		arrayToSwitch.set(int1, arrayToSwitch.get(int2));
		arrayToSwitch.set(int2,placeHolder);
		
		
	}
	
	private Boolean testOperators(ArrayList<Integer> arrayToTest) {
		String str_i = new String();
		String str_j = new String();
		String str_m = new String();
		String str_k = new String();
		
		float result = 0;
		//System.out.println("The numbers are: " + );
		for(int i = 0; i < 2; i++) {
			str_i = "";
			
			float result_i = 0;
			//To see if the first number is - or +
			switch(i) {
			
				case 0:
					result_i = (float) 0 + arrayToTest.get(0);
					str_i += arrayToTest.get(0);
					break;
					
				case 1:
					result_i = (float) 0 - arrayToTest.get(0);
					str_i += "-" + arrayToTest.get(0);
					break;
			}
			
			for(int j = 0; j < 4; j++) {
				float result_j =0;
				str_j = "";
				
				switch(j) {
					
					case 0:
						result_j = (float) (result_i) + (arrayToTest.get(1));
						str_j = str_i + "+" + arrayToTest.get(1);
						break;
					case 1:
						result_j = (float) (result_i) - (arrayToTest.get(1));
						str_j = str_i + "-" + arrayToTest.get(1);
						break;
					case 2:
						result_j = (float) (result_i) * (arrayToTest.get(1));
						str_j = str_i + "x" + arrayToTest.get(1);
						break;
					case 3:
						result_j = (float) (result_i) / (arrayToTest.get(1));
						str_j = str_i + "/" + arrayToTest.get(1);
						break;
				}
				
				
				
				for(int k = 0; k < 4; k++) {
					str_k = "";
					
					float result_k = 0;
					switch(k) {
						case 0:
							result_k = (float) (result_j) + (arrayToTest.get(2));
							str_k = str_j + "+" + arrayToTest.get(2);
							break;
						case 1:
							result_k = (float) (result_j) - (arrayToTest.get(2));
							str_k = str_j + "-" + arrayToTest.get(2);
							break;
						case 2:
							result_k = (float) (result_j) * (arrayToTest.get(2));
							str_k = str_j + "x" + arrayToTest.get(2);
							break;
						case 3:
							result_k = (float) (result_j) / (arrayToTest.get(2));
							str_k = str_j + "/" + arrayToTest.get(2);
							break;
					}
					
					
					
					for(int m = 0; m < 4; m++) {
						str_m = "";
						float result_m = 0;
						
						switch(m) {
							case 0:
								result_m = (float) (result_k) + (arrayToTest.get(3));
								str_m = str_k + "+" + arrayToTest.get(3);
								break;
							case 1:
								result_m = (float) (result_k) - (arrayToTest.get(3));
								str_m = str_k + "-" + arrayToTest.get(3);
								break;
							case 2:
								result_m = (float) (result_k) * (arrayToTest.get(3));
								str_m = str_k + "x" + arrayToTest.get(3);
								break;
							case 3:
								result_m = (float) (result_k) / (arrayToTest.get(3));
								str_m = str_k + "/" + arrayToTest.get(3);
								break;
						}
						
						if(result_m == TwentyFour) {
							System.out.println("The right combination is:");
							System.out.println(str_m);
							//return true;
						}
						
					}
					
				}
				
			}
			
		}
		
		return false;
	}
	
	void permuteArray(ArrayList<Integer> arr, int ibegin, int iend)
	{
		   int i;
		   if (ibegin == iend)
		   {
			   
			   if(this.testOperators(arr) == true) {
				   //System.out.println("The correct answers is: " + this.stringRes);
				   //return;
				   
			   }
		   
			   //System.out.println(arr.toString());
		   }
		   else
		   {
		       for (i = ibegin; i <= iend; i++)
		       {
		    	  switchValues(arr, ibegin, i);
		    	  permuteArray(arr, ibegin+1, iend);
		    	  switchValues(arr, ibegin, i);
		          //swap((a+l), (a+i));
		          //permute(a, l+1, r);
		          //swap((a+l), (a+i)); //backtrack
		       }
		   }
		
		   
	}
	
	
	Boolean sortNumbers() {
		
		ArrayList<Integer> previousNumbers = new ArrayList<Integer>();
		
		for(int i = 0; i < 4; i++) {
			
			//if(previousNumber == )
			
			
			
			for(int j = 1; j < 4; j++) {
				
				System.out.println(numbers.toString());
				
				
				for(int k = 2; k < 4; k++) {
					
					numbers = referenceNumbers;
					this.switchValues(numbers, 2, k);
					
					previousNumbers = numbers;
					
					System.out.println(numbers.toString());
					
					//if(testOperators(numbers) == true) {
					//	return new Boolean(true);
					//}
					
				}
				
				
				//System.out.println(numbers.toString());
				numbers = referenceNumbers;
				this.switchValues(numbers, 1, j);
				System.out.println(numbers.toString());
				
				
				//if(testOperators(numbers) == true) {
				//	return new Boolean(true);
				//}
				
				
			}
			
			//System.out.println(numbers.toString());
			numbers = referenceNumbers;
			this.switchValues(numbers, 0, i);
			System.out.println(numbers.toString());
			
			
			//if(testOperators(numbers) == true) {
			//	return new Boolean(true);
			//}
			
		}
		
		
		return new Boolean(false);
		
	}
	
}
