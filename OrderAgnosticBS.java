import java.util.Scanner;

public class OrderAgnosticBS {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int n = in.nextInt();
        int[] a = new int[n];
        System.out.print("Enter elements in ascending/descending order: ");
        for (int i = 0; i < n; i++)
            a[i]= in.nextInt();
        System.out.print("Enter element to be searched: ");
        int t = in.nextInt();
        System.out.println(binarySearch(a,t));
    }

    private static int binarySearch(int[] a, int t) {
        int start = 0, end = a.length - 1;
        boolean x = a[start] < a[end];
        while (start<=end){
//            int mid = (start + end)/2; //might be possible that (start + end) exceed the int range while calculating
            int mid = start + (end-start)/2 ;
            if(t==a[mid])
                return mid;
            else if (t<a[mid])
                if (x)
                    end = mid-1;
                else
                    start = mid+1;
            else if (t>a[mid])
                if (x)
                    start = mid+1;
                else
                    end = mid-1;
        }
        return -1;
    }
}
