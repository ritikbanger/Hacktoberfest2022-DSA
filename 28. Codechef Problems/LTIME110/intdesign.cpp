#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,x1,y1,x2,y2,a,b;
	cin>>t;
	while(t!=0)
	{
	    cin>>x1>>y1>>x2>>y2;
	    a=x1+y1;
	    b=x2+y2;
	    if(a<=b)
	    {
	        cout<<a<<endl;
	    }
	    else
	    cout<<b<<endl;
	   t--;
	}
	return 0;
}