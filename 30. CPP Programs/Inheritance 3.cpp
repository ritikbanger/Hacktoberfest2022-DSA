#include<iostream>
using namespace std;
class shape
{
    protected:
                float width,height;
    public:
                shape()
                {
                    cout<<"Enter the value of width: "<<endl;
                    cin>>width;
                    cout<<"Enter the value of height: "<<endl;
                    cin>>height;
                }
};
class rectangle: public shape
{
    private:    
                float ar;
    public:
                void area_rec()
                {
                    ar = height * width;
                    cout<<"The area of rectangle is: "<<ar<<endl;
                }
};
class triangle: public shape
{
    private:
                float ar;
    public:
                void area_tri()
                {
                    ar = 0.5 * height * width;
                    cout<<"The area of triangle is: "<<ar<<endl;
                }

};
int main()
{
    cout<<"FOR TRIANGLE"<<endl;
    triangle obj;
    obj.area_tri();
    cout<<"FOR RECTANGLE"<<endl;
    rectangle ob;
    ob.area_rec();
    return 0;
}