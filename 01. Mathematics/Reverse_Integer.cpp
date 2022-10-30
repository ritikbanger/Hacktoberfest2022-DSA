class Solution {
public:
    int reverse(int x) {
        long int n=x;
        long int rev=0;
        
        if(n<0){
            n=-n;
        }
        while(n>0){
            int a= n%10;
           rev = (rev*10)+a;
            n=n/10;
        }
        
        long int u = pow(2,31);
        
        if(rev>u){
            return 0;
        }
        
        if(x>=0){
            return rev;
        }
       
        return -rev; 
        

        
    }
};
    
