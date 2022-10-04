import java.util.Scanner;

public class BuyingTorches {
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        int test = scan.nextInt();
        while (test-- >0)
        {
            long x = scan.nextLong();
            long y = scan.nextLong();
            long k = scan.nextLong();
            long reqSticksForCrafting = y*k+k;
            long i=0;
            if((reqSticksForCrafting -1)%(x-1)==0)
            {
                i = (reqSticksForCrafting -1)/(x-1);
            }
            else {
                i = (reqSticksForCrafting -1)/(x-1) + 1;
            }

            System.out.println(i+k);



        }
    }
}