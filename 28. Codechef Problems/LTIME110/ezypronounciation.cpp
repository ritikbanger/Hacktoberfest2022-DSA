#include <iostream>
#include<string.h>

using namespace std;

int main() {
	// your code goes here
	
	int tc;
	cin>>tc;
	while(tc--){
	    int n;
	    cin>>n; 
	    string s;
	    
	    cin>>s;
	    int count =0;
	    
	    for(int i=0;i<n;i++){
	        if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u' ){
	            count ++;
	             if(count==4){
	                 break;
	             }
	        }
	        else{
	            count=0;
	    }
 } 
	   if(count>=4){
	        cout<<"NO"<<endl;
	    }
	    else{
	        cout<<"YES"<<endl;
	        count=0;
	    }
	}	
	
	return 0;
}