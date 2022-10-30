#include<iostream>
using namespace std;
class TollBooth
{
    private:
                unsigned int cars;
                double amount;
    public:
                void setvalue()
                {
                    cars=0;
                    amount=0;
                }
                void PayingCar()
                {
                    cars++;
                    amount+=0.5;
                }
                void nonPayCar()
                {
                    cars++;
                }
                void Display()
                {
                    cout<<"total number of cars = "<<cars<<endl;
                    cout<<"Total cash = "<<amount;
                }
};
int main()
{
    TollBooth ob;
    int i;
    char c;
    ob.setvalue();
    do
    {
    cout<<"Enter the key"<<endl;
    cout<<"A. Paying Car"<<endl;
    cout<<"B. non Paying car"<<endl;
    cout<<"E. Display the total"<<endl;
    cin>>c;
    switch(c)
    {
        case 'A': ob.PayingCar();
                    i++;
                    break;
        case 'B': ob.nonPayCar();
                    i++;
                    break;
        case 'E': ob.Display();
                    i=0;
                    break;
        default: cout<<"Invalid choice";
    }
    }while(i!=0);
    return 0;
}