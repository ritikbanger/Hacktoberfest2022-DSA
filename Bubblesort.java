public class Tester {
   static void bubbleSort(int[] arr) {  
      int n = arr.length;  
      int temp = 0;  
      for(int i = 0; i < n; i++){  
         for(int j = 1; j < (n-i); j++){  
            if(arr[j-1] > arr[j]){  
               //swap elements  
               temp = arr[j-1];  
               arr[j-1] = arr[j];  
               arr[j] = temp;  
            }          
         }  
      }
   }  
   public static void main(String[] args) {  
      int arr[] = {21,60,32,01,41,34,5};
      System.out.println("Before Bubble Sort");  
      for(int i = 0; i < arr.length; i++){  
         System.out.print(arr[i] + " ");  
      }  
      System.out.println();  
      bubbleSort(arr);
      System.out.println("After Bubble Sort");  
      for(int i = 0; i < arr.length; i++){  
         System.out.print(arr[i] + " ");  
      }  
   }
}
