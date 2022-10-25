#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int x,y,z;
	    cin>>x>>y>>z;
	    long int p;
	    p=(x*y);
	    if(x>3)
	    p+=z*(x/3);
	    if(x%3==0 && x>3)
	    p-=z;
	    cout<<p<<endl;
	}
	return 0;
}