class example{  
 public static void main(String args[]){  
  int r,sum=0,temp;    
  int n=100;
  temp=n;    
  while(n>0){    
   r=n%10; 
   sum=(sum*10)+r;    
   n=n/10;    
  }    
  if(temp==sum)    
   System.out.println("palindrome");    
  else    
   System.out.println("not palindrome");    
}  
}  


class Solution {
    public boolean isPalindrome(int x) {
        int temp=x;
        int rev=0;

        while(x>0)
        {
           int rem=x%10;
           rev=(rev*10)+rem;
            x=x/10;
        }
        if(rev==temp)
           return true;
        else 
           return false;

        
    }
}
