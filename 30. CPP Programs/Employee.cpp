#include<iostream>
using namespace std;
class employee
{
    private: int Pan,Taxincome;
             char Name[20];
            float Tax;
    public: void inputinfo()
        {
            cin>>Pan>>Name>>Taxincome;
        }
        void Taxcalc()
        {
            if(Taxincome<=250000)
            Tax=0;
            else if(Taxincome>250000 && Taxincome<=300000)
            Tax=(Taxincome-2500000)*0.1;
            else if(Taxincome>300000 && Taxincome<=400000)
            Tax=5000+((Taxincome-300000)*0.2);
            else if(Taxincome>400000)
            Tax=25000+((Taxincome-400000)*0.3);
        }
        void Displayinfo()
        {
            cout<<Name<<"\n"<<Pan<<"\n"<<Taxincome<<"\n"<<Tax;
        }
};
int main()
{
    employee ob;
    ob.inputinfo();
    ob.Taxcalc();
    ob.Displayinfo();
    return 0;
}