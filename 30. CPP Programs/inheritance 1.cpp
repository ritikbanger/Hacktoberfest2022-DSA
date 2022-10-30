#include<iostream>
using namespace std;
class Mammals
{
public:
        void display1()
        {
            cout<<"I am mammal"<<endl;
        }
};class MarineAnimals
{
public:
        void display2()
        {
            cout<<"I am a Marine Animal"<<endl;
        }
};
class BlueWhale:public Mammals,public MarineAnimals
{
public:
        void display()
        {
            cout<<"I belong to both the categories: Mammals as well as Marine Animals"<<endl;
        }
};
int main()
{
    Mammals obm;
    MarineAnimals obma;
    BlueWhale obbw;
    obm.display1();
    obma.display2();
    obbw.display();
    obbw.display1();
    obbw.display2();
    return 0;
}