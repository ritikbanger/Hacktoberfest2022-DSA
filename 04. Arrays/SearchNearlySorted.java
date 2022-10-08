// search in nearly sorted array

public class SearchNearlySorted {
    public static void main(String[] args) {
        
        int[] arr = {10,20,40,30,50};
        int target = 40;

        System.out.println(Search(arr, target));
    }

    static int Search(int[] arr, int target){
        int start = 0;
        int end = arr.length-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(arr[mid]==target){
                return mid;
            }
            if(arr[mid+1]==target){
                return mid+1;
            }
            if(arr[mid-1]==target){
                return mid-1;
            }
            else if(arr[mid]>target){
                end = mid-2;
            }
            else{
                start = mid+2;
            }
        }
        return -1;
    }
}
