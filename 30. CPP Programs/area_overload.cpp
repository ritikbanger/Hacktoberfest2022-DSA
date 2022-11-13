#include <iostream>
#include <cmath>
using namespace std;
class area
{
  public:
  void calc(int a)
  {
      cout<<"The area to the square is: "<<(a*a)<<endl;
  }
  void calc(int a,int b)
  {
      cout<<"The area of the rectangle is:  "<<(a*b)<<endl;
  }
  void calc(int a,int b,int c)
  {
      float s=(a+b+c)/2;
      float t=sqrt(s*(s-a)*(s-b)*(s-c));
      cout<<"The area of the triangle is: "<<t<<endl;
  }
};
int main()
{
    area obj;
    int s,l,b,x,y,z;
    cin>>s;
    obj.calc(s);
    cin>>l>>b;
    obj.calc(l,b);
    cin>>x>>y>>z;
    obj.calc(x,y,z);
}