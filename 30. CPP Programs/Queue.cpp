/* Name - Satyam Gupta
    Roll no -32
    CST
    QUEUE*/
#include <iostream>
#define MAX 10
using namespace std;

class Queue
{
private:
    int queue[MAX], rear, front, x, *dyn = NULL, dyn_size;

public:
    Queue()
    {
        rear = -1;
        front = -1;
    }

    void stat_enqueue()
    {
        if (rear == MAX - 1)
        {
            cout << "Queue is overflow." << endl;
        }
        else if (front == -1 && rear == -1)
        {
            rear++;
            cout << "Enter the value : ";
            cin >> x;
            queue[rear] = x;
            front++;
        }
        else
        {
            rear++;
            cout << "Enter the value : ";
            cin >> x;
            queue[rear] = x;
        }
    }

    void stat_dequeue()
    {
        if (front == -1 &&rear==-1)
        {
            cout << "Queue is underflow." << endl;
        }
        else if (front == rear)
        {
            cout << queue[front] << " element is dequeued." << endl;
            front = rear = -1;
        }
        else
        {
            cout << queue[front] << " element is dequeued." << endl;
            front++;
        }
    }

    void stat_display()
    {
        int temp=front;
        if (front == -1)
        {
            cout << "Queue is underflow";
        }
        else
        {
            cout << "Queue :-" << endl;
            while (temp<=rear)
            {
                cout<<queue[temp]<<"\t";
                temp++;
            }
            cout << endl;
        }
    }

    void getdyn_size()
    {
        cout << "Enter size of queue : ";
        cin >> dyn_size;
        dyn = new int[dyn_size];
    }
    void dyn_enqueue()
    {
        if (rear == dyn_size - 1)
        {
            cout << "Queue is overflow." << endl;
        }
        else if (front == -1 && rear == -1)
        {
            rear++;
            cout << "Enter the value : ";
            cin >> x;
            *(dyn+rear)=x;
            front++;
        }
        else
        {
            rear++;
            cout << "Enter the value : ";
            cin >> x;
            *(dyn+rear) = x;
        }
    }

    void dyn_dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is underflow." << endl;
        }
        else if (front == rear)
        {
            cout << *(dyn+front)<< " element is dequeued." << endl;
            front = rear = -1;
        }
        else
        {
            cout << *(dyn+front) << " element is dequeued." << endl;
            front++;
        }
    }

    void dyn_display()
    {
        int temp=front;
        if (front == -1&&rear==-1)
        {
            cout << "Queue is underflow." << endl;
        }
        else
        {
             cout<<"Queue :-"<<endl;
             while(temp<=rear)
             {
                 cout<<*(dyn+temp)<<"\t";
                 temp++;
             }
             cout<<endl;
        }
    }

    void circular_enqueue()
    {
        if ((rear + 1) % dyn_size == front)
        {
            cout << "Queue is overflow." << endl;
        }
        else
        {
            rear = (rear + 1) % dyn_size;
            cout << "Enter the value : ";
            cin >> x;
            *(dyn+rear)= x;
            if(front==-1)
            front=rear;
        }
    }

    void circular_dequeue()
    {
        if(front==-1&&rear==-1)
        {
            cout<<"Queue is underflow."<<endl;
        }
        else if (front == rear)
        {
			cout<<*(dyn+front)<<" element is dequeued."<<endl;
			front=rear=-1;
        }
        else
        {
            cout <<*(dyn+front) << " element is dequeued." << endl;
            front = (front + 1) % dyn_size;
        }
    }

    void circular_display()
    {
        int temp=front;
        if(front==-1&&rear==-1)
        {
            cout<<"Queue is underflow."<<endl;
        }
        else
        {
           while (temp!=rear)
           {
               cout<<*(dyn+temp)<<"\t";
               temp=(temp+1)%dyn_size;
           }
           cout<<*(dyn+temp)<<"\t";
        }
        cout<<endl;
    }
};
int main()
{
    Queue q1;
    int ch, ch1;
    cout << "1.Static Queue\n2.Dynamic Queue\n3.Circular Queue." << endl;
    cout << "Enter your choice : ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        while (1)
        {
            cout << "1.Enqueue\n2.Dequeue\n3.Display\n4.Exit" << endl;
            cout << "Enter choice : ";
            cin >> ch1;
            switch (ch1)
            {
            case 1:
                q1.stat_enqueue();
                break;
            case 2:
                q1.stat_dequeue();
                break;
            case 3:
                q1.stat_display();
                break;
            case 4:
                return 0;

            default:
                cout << "Entered wrong choice." << endl;
                break;
            }
        }
        break;

    case 2:
        q1.getdyn_size();
        while (1)
        {
            cout << "1.Enqueue\n2.Dequeue\n3.Display\n4.Exit" << endl;
            cout << "Enter choice : ";
            cin >> ch1;
            switch (ch1)
            {
            case 1:
                q1.dyn_enqueue();
                break;
            case 2:
                q1.dyn_dequeue();
                break;
            case 3:
                q1.dyn_display();
                break;
            case 4:
                return 0;
            default:
                cout << "Entered wrong choice." << endl;
                break;
            }
        }
    case 3:
        q1.getdyn_size();
        while (1)
        {
            cout << "1.Enqueue\n2.Dequeue\n3.Display\n4.Exit" << endl;
            cout << "Enter choice : ";
            cin >> ch1;
            switch (ch1)
            {
            case 1:
                q1.circular_enqueue();
                break;
            case 2:
                q1.circular_dequeue();
                break;
            case 3:
                q1.circular_display();
                break;
            case 4:
                return 0;
            default:
                cout << "Entered wrong choice." << endl;
                break;
            }
        }
    default:
        cout << "Entered wrong choice." << endl;
        break;
    }
}