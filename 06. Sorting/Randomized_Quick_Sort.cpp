#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<math.h>
using namespace std;
#define MAX 1000
template<class t>
class q_sort
{
public:
t a[MAX];
int count, n;
void input();
void output();
int quicksort(t a[] ,int p,int r);
int partition(t a[],int p,int r);
qsort()
{
count=0;
}
};
template<class t>
void q_sort<t>::input()
{
int i;
for(i=1;i<=n;i++)
{
a[i]=rand()% 100;
}
}
template<class t>
void q_sort<t>::output()
{
for(int i=1;i<=n;i++)
cout<<a[i]<<"\t";
}
template<class t>
int q_sort<t>::quicksort(t a[],int p, int r)
{
	int q;
if(p<r)	
{
q=partition(a,p,r);
quicksort(a,p,q-1);
quicksort(a,q+1,r);
}
return count;
}
template<class t>
int q_sort<t>::partition(t a[],int p, int r)
{
int i,j,x,temp;
x = a[r];
i=p-1;
for(j=p;j<=r-1;j++)
{
	if(a[j]<=x)
	{
		i=i+1;
		temp=a[j];
		a[j]=a[i];
		a[i]=temp;
	}
	count++;
}
temp=a[i+1];
a[i+1]=a[r];
a[r]=temp;
return i+1;
}
int main()
{
int size, c;
ofstream o;
o.open("Quicksortgraph.csv",ios::app);
cout<<"\t QUICK SORT with time complexities graph \n";
q_sort<int>list;
cout<<"Enter the size : ";
cin>>size;
if(size<30||size>1000)
{
cout<<"Invalid!! Enter again!!!";
cin>>size;
}
else
{
o<<"Size(n), Number of comparisons, log(n), n*n, nlog(n)"<<endl;
for(int k=size;k<=1000;k+=30)
{
list.n=k;
list.input();
list.quicksort(list.a,1,list.n);
list.output();
cout<<"Number of comparisons : "<<list.count;
o<<k<<","<<list.count<<","<<log2(k)<<","<<k*k<<","<<k*log2(k)<<endl;
}
}
o.close();
return 0;
}
