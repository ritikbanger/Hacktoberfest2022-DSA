#include<iostream>
using namespace std;
class PRODUCT
{
    private: 
                string Pid;
                string Pname;
                string remarks;
                int Pcostprice,Psellingprice,margin;
    public: 
                void setRemarks(int sp,int cp)
                {
                    margin=(sp-cp);
                    if(margin<0)
                        remarks = "Loss";
                    else if(margin>0)
                        remarks = "Profit";
                }
                void Getdetials()
                {
                    cout<<"Enter Product ID"<<endl;
                    getline(cin,Pid);
                    cout<<"Enter Product name"<<endl;
                    getline(cin,Pname);
                    cout<<"Enter Cost Price"<<endl;
                    cin>>Pcostprice;
                    cout<<"Enter Selling Price"<<endl;
                    cin>>Psellingprice;
                    setRemarks(Psellingprice,Pcostprice);
                    cin.clear();
                    cin.sync();
                }
                void Setdetails()
                {
                    cout<<"Product ID = "<<Pid<<endl;
                    cout<<"Product Name = "<<Pname<<endl;
                    cout<<"Cost price = "<<Pcostprice<<endl;
                    cout<<"Selling price = "<<Psellingprice<<endl;
                    cout<<"Remarks = "<<remarks<<endl;
                }

};
int main()
{
    PRODUCT ob[5];
    int i;
    for(i=1;i<=5;i++)
    {
        cout<<"Enter the details of "<<i<<" product"<<endl;
        ob[i].Getdetials();
        cout<<"The details about "<<i<<" product"<<endl;
        ob[i].Setdetails();
    }
    return 0;
}