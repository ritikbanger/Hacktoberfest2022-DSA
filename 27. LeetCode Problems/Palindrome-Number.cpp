/*
9. Palindrome Number

Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward.

For example, 121 is a palindrome while 123 is not.
  
*/
class Solution {
public:
    bool isPalindrome(int x) {
      if(x==0){
          return true;
      }
        if(x<0 || x%10==0){
            return false;
        }
        
        int temp = x;
        int rev = 0;
        
        while(temp!=0){
            int rem = temp%10;
            temp = temp/10;
            
            rev = rev*10+rem;
        }
        if(x==rev){
            return true;
        }
        else{
            return false;
        }
    }
};
