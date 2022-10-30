#include<iostream>
using namespace std;
class queue
{
    int *arr;
    int front,rear,size;
    public:
    void init(int n)
    {
        size=n;
        arr=new int[n];
        front=rear=-1;
    }
    int isempty()
    {
        return rear==-1;
    }
    int isfull()
    {
        return (((rear==size-1)&&front==0)|| front==rear+1);
    }
    void enqueue(int data)
    {
        if(isfull())
        return;
        else
        {
            if(front==-1)
            front=0;
            if(rear!=size-1)
            rear++;
            else
            rear=0;
            arr[rear]=data;
        }
    }
    int dequeue()
    {
        if(isempty())
        return 5674;
        else
        {
            int temp=arr[front];
            if(front==rear)
            front=rear=-1;
            else if(front!=size-1)
            front++;
            else front=0;
            return temp;
        }
    }

};
int main()
{
    queue q;
    q.init(6);
    q.enqueue(45);
    q.enqueue(60);
    q.enqueue(34);
    q.enqueue(55);
    q.enqueue(90);
    q.enqueue(76);
    cout<<"Deleted item:"<<q.dequeue()<<endl;
    cout<<"Deleted item:"<<q.dequeue()<<endl;
    cout<<"Deleted item:"<<q.dequeue()<<endl;
    return 0;
}


// The up defined code can be implemented manually as well...
// The following code can do so,

/*#include<iostream>
#include<string>
using namespace std;
int n;
int back=-1;
int front=-1;
bool isEmpty(){
	if(front==-1&&back==-1)
	  return true;
	else
	  return false;  
}
bool isFull(){
	if((back+1)%n==front)
	 return true;
	else
	 return false; 
}
int EnQueue(int m[]){
	if(isFull())
		cout<<"The Queue is already full !";
	else if(isEmpty()){
	   front=back=0;	
	} 
	else
	   back=(back+1)%n;
	int val;
	n++;
	cout<<"Enter the value to Enqueue"<<endl;
	cin>>val;
	for(int i=n;i>0;i--)
	{
		m[i]=m[i-1];
	}
	m[back]= val;   
}
int DeQueue(int m[]){
	if(isEmpty())
	 	cout<<"The Queue is Empty !";
	else if(front==back){
		m[front]= 0;
		front=back=-1;}
	else {
		m[front]= 0;
		front=(front+1)%n;
	}	
		
	
}
int main(){
	int arr[n];
	int value;
	int position;
	cout<<"Welcome to the Queue"<<endl;
	cout<<"Enter the size of the Queue"<<endl;
	cin>>n;
	for(int i=0; i<n;i++){
		cout<<"Enter "<<i+1<<" element of array"<<endl;
		cin>>value;
		arr[i]= value;	
	}
	do{
		cout<<"Choose the option to execute a function."<<endl;
		cout<<"0. Exit the program"<<endl;
		cout<<"1. isFull()"<<endl;
		cout<<"2. isEmpty()"<<endl;
		cout<<"3. EnQueue()"<<endl;
		cout<<"4. DeQueue()"<<endl;
		cout<<"5. display()"<<endl;
		cin>>position;
		switch(position){
			case 0:
				cout<<"Program eliminated"<<endl;
				break;
			case 1:
			    cout<<"isFull() is called"<<endl;
				isFull();
				break;
			case 2:
			    cout<<"isEmpty() is called"<<endl;
				isEmpty();
				break;
			case 3:
			    cout<<"EnQueue() is called"<<endl;
				EnQueue(arr);
				break;
			case 4:
			    cout<<"DeQueue() is called"<<endl;
				DeQueue(arr);
				break;
			case 5:
			    for(int j=0; j<n; j++)
				 cout<<arr[j]<<endl;
			   	 break;
			default:
			   cout<<"You have entered inappropriate input"<<endl;
			   break;						
		}
	}while(position!=0);
	return 0;
}*/
