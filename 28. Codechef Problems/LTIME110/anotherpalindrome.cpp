#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    string a,b;
	    for(int i=0;i<n;i+=2){
	       a+=s[i];
	    }
	    for(int i=1;i<n;i+=2){
	        b+=s[i];
	    }
	    sort(a.begin(),a.end());
	    sort(b.begin(),b.end());
	    if(a==b){
	        cout<<"YES"<<endl;
	    }
	    else
	    cout<<"NO"<<endl;
	    
	}
	return 0;
}