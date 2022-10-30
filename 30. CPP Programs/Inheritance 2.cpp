#include<iostream>
using namespace std;
class Apples
{
    protected:
                int a;
    public:
                void c_apples()
                {
                    cout<<"Enter number of apples"<<endl;
                    cin>>a;
                }
                void display_c_apples()
                {
                    cout<<"The number of apples are: "<<a<<endl;
                }

};
class Mangoes
{
    protected:
                int m;
    public:
                void c_mangoes()
                {
                    cout<<"Enter number of mangoes: "<<endl;
                    cin>>m;
                }
                void display_c_mangoes()
                {
                    cout<<"The number of mangoes are: "<<m<<endl;
                }
};
class Fruit:public Apples,public Mangoes
{
    private:
                int t,n;
    public:
                void total_fruits()
                {
                    cout<<"Enter the number of fruits other than apples and mangoes: "<<endl;
                    cin>>n;
                    t=n+a+m;
                }
                void display_t_fruits()
                {
                    cout<<"The total number of fruits are: "<<t<<endl;
                }
};
int main()
{
    Fruit ob;
    ob.c_apples();
    ob.c_mangoes();
    ob.total_fruits();
    ob.display_c_apples();
    ob.display_c_mangoes();
    ob.display_t_fruits();
    return 0;
}