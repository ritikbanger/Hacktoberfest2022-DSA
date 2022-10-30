#include<iostream>
using namespace std;
class Mother
{
    public:
            void display()
            {
                cout<<"I am mother"<<endl;
            }
};
class Daughter:public Mother
{
    public:
            void display()
            {
                cout<<"I am daughter"<<endl;
            }
};
int main()
{
    Daughter ob;
    ob.display();
    return 0;
}
