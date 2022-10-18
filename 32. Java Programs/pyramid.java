import java.util.Scanner;

public class pyramid {
	 public static void main(String[] args) {
		 System.out.print("Please, enter height of the pyramid: ");
	        
	       Scanner input= new Scanner(System.in);
	       int h= input.nextInt();
	       for(int i=0; i<h; i++)
	       {
	           for(int j=0; j<=i; j++)
	           {
	               System.out.print("*");
	           }
	           System.out.println();  
	       }
	       for (int i = h - 1; i > 0; i--) {
				for (int j = 0; j < i; j++) {
					System.out.print("*");
				}
				System.out.println();	
			}
	       
	    }

	    }

