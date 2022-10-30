#include<iostream>
#include<string>
using namespace std;
class bankdetail
{
	private:
	string name;
	string address;
	int accountno;
	float balance;
	public:
	  void inputdata()
    {
    	cout<<"enter account holders name = "<<endl;
    	getline(cin,name);
    	cout<<"enter holders address = "<<endl;
		getline(cin,address);
    	cout<<"enter account number = "<<endl;
		cin>>accountno;
		cout<<"enter amount in holders account = "<<endl; 
		cin>>balance; 
        cin.clear();
         cin.sync();
	} 
		void showdata()
	{
		cout<<"account holders name = "<<name<<endl;
		cout<<"account number = "<<accountno<<endl; 
		cout<<"holders address = "<<address<<endl;
		cout<<"amount in holders account = "<<balance<<endl; 
	}
		void deposit()
	{
		int add_amount;
		cout<<" amount you want to deposit in your account = "<<endl;
		cin>>add_amount;
		balance=balance+add_amount;	
		cout<<"new deposirt money = "<<balance<<endl;
	}
	void withdrawl()
	{
		int withdrawl_amount;
		cout<<"enter the  amount you want to withdrawl = "<<endl;
		cin>>withdrawl_amount;
		balance=balance-withdrawl_amount;
		cout<<"amount after withdrawing money = "<<balance<<endl;
	}
	void address_change()
	{
		string new_address;
		cout<<"new address  = "<<endl;
		cin>>new_address;
		address=new_address;
	}

int search(int a)
{
	if(accountno==a)
	{
	showdata();
 }
  return 0 ;
}
};

int  main()
{
	bankdetail data[2];
	int ch,temp=0,a;
	char ch2;
	for(int i=0;i<5;i++)
	{
	data[i].inputdata();
    }
	do
	{
		cout<<"1-show all detail"<<endl;
		cout<<"2-search by acc no"<<endl;
		cout<<"3-deposit "<<endl;
		cout<<"4-withdrawl your amount"<<endl;
		cout<<"5-change address your address"<<endl;
		cout<<"6-exit"<<endl;
		cout<<"pleease enter your choice = "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				
				for(int i=0;i<2;i++)
				{
				   data[i].showdata();
			    }
				break;
			case 2:
				
					cin>>a;
					for(int i=0;i<2;i++)
					{
						temp=data[i].search(a);
						if(temp)
						{
							data[i].showdata();
							break;
				        }
				        if(!temp)
				        {
						  cout<<"no detail found";
					    }
					}
					break;
		
			case 3:
			   	cin>>a;
			   	for(int i=0;i<2;i++)
			   	{
			   		temp=data[i].search(a);
			   		if(temp)
			   		{
			   			data[i].deposit();
			   	    	data[i].showdata();
			   	    	break;
					   }
					   if(!temp)
					   {
					   	cout<<"no detail found";
					   }
				}
				break;
				
			case 4:
				cin>>a;
					for(int i=0;i<2;i++)
			   	{
			   		temp=data[i].search(a);
			   		if(temp)
			   		{
			   			data[i].withdrawl();
			   	    	data[i].showdata();
			   	    	break;
					   }
					   if(!temp)
					   {
					   	cout<<"no detail found";
					   }
				}
				break;
				
			case 5:
            cout<<"enter the acc no. whose data you want to change = ";
            cin>>a;
                for(int i=0;i<2;i++)
                {
                    temp = data[i].search(a);
                    if(temp)
                    {
                        data[i].address_change();
                        data[i].showdata();
                        break;
                    }
                    if(!temp)
                    cout<<"no detail found";
                }
                break;
             case 6:
                    cout<<"thank you"<<endl;
                    break;
            default:
                {
                    cout<<""<<endl;
                }
                
        }
        cout<<"do you want to continue (y/n)"<<endl;
        cin>>ch2;
    }while(ch2=='Y'||ch2=='y');
    return 0;
}