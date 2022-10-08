#include<iostream.h> 
using namespace std; 
 int main()
  {
   int row,i,j,k;
   cout<<"Enter the number: "; cin>>row;

   cout<<endl;

   int upper = row;
//upper part
     for(i=1;i<upper;i++)
       {
	 for(j=1;j<=upper-i;j++)
	   cout<<" ";

	 for(k=1; k<=i*2-1; k++)
	  {
	    if(i<=upper/2)
	       cout<<" ";
	    else if(i==(upper/2)+1)
	       cout<<"*";
	    else if(k==1|| k==i*2-1)
	       cout<<"*";
	    else if(i==upper-1)
	       cout<<" ";
	    else cout<<" ";
	  }
	 cout<<endl;
      }

//lower part

   int lower=row;
   for(i=1;i<=lower;i++)
     {
       for(j=1;j<=i+1;j++)
	   cout<<" ";

       for(k=1; k<=(lower-i)*2-3; k++)
	   cout<<i;
	 
       cout<<endl;
     }
return 0;
 }
