#include<iostream>
using namespace std;
class Animal
{
   private:
            string name;
            int age;
    public:
            void set_value()
            {
                cout<<"Enter name: "<<endl;
                getline(cin,name);
                cout<<"Enter age: "<<endl;
                cin>>age;
            }
            void display()
            {
                cout<<"The age is: "<<age<<endl;
                cout<<"Name is: "<<name<<endl;
                if(name=="zebra"||name=="Zebra")
                {
                    cout<<"The origin is Africa"<<endl;
                    cout<<"The color is black and white"<<endl;
                }
                else if(name=="dolphin"||name=="Dolphin")
                {
                    cout<<"The origin is Miocene Epoch"<<endl;
                    cout<<"The color is whitish-grey"<<endl;
                }
                else
                cout<<"Incorrect input";
            }
};
int main()
{
    Animal ob;
    ob.set_value();
    ob.display();
    return 0;
}