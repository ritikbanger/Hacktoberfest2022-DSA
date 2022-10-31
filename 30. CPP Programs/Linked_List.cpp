/* Name - Satyam Gupta
    Roll no -32
    CST
    LINKED LIST*/
#include <iostream>
using namespace std;

class LinkedList
{
private:
    typedef struct node
    {
        int info;
        struct node *next;
    } nodetype;

    typedef struct NODE
    {
        struct NODE *prev;
        int info;
        struct NODE *next;
    } NODE;

    nodetype *first = NULL, *last = NULL;
    NODE *f = NULL, *l = NULL;
    int len = 0;

public:
    void single_create()
    {
        int x;
        nodetype *p = NULL;
        p = new nodetype();
        cout << "Enter value : ";
        cin >> x;
        p->info = x;

        if (first == NULL && last == NULL)
        {
            first = last = p;
        }
        else
        {
            last->next = p;
            last = p;
        }
        last->next = NULL;
        len++;
    }
    void single_delete(int pos)
    {
        nodetype *p = new nodetype();
        nodetype *q = new nodetype();
        if (pos <= len)
        {
            q = first;
            if (pos == 1)
            {
                first = first->next;
                cout << q->info << " is deleted." << endl;
                free(q);
            }
            else if (pos == len)
            {
                while (q != NULL)
                {
                    p = q;
                    q->next;
                }
                cout << q->info << " node is deleted." << endl;
                last = p;
                p->next = NULL;
                free(q);
            }
            else
            {
                for (int i = 0; i < pos - 1; i++)
                {
                    p = q;
                    q = q->next;
                }
                cout << q->info << " node is deleted." << endl;
                p->next = q->next;
                p = q->next;
                free(q);
            }
        }
        else
        {
            cout << "Position does not exist." << endl;
        }
    }
    void single_display()
    {
        nodetype *p = new nodetype();
        p = first;
        while (p != NULL)
        {
            cout << p->info << "\t";
            p = p->next;
        }
        cout << endl;
    }

    void circular_create()
    {
        int x;
        nodetype *p = new nodetype();
        cout << "Enter Value : ";
        cin >> x;
        p->info = x;
        if (first == NULL && last == NULL)
        {
            first = last = p;
        }
        else
        {
            last->next = p;
            last = p;
        }
        last->next = first;
        len++;
    }
    void circular_delete(int pos)
    {
        nodetype *p = new nodetype();
        nodetype *q = new nodetype();
        if (pos <= len)
        {
            q = first;
            if (pos == 1)
            {
                cout << q->info << " node is deleted." << endl;
                first = q->next;
                last->next = q->next;
                free(q);
            }
            else if (pos == len)
            {
                do
                {
                    p = q;
                    q = q->next;
                } while (q != first);
                cout << q->info << " node is deleted." << endl;
                last = p;
                p->next = q->next;
                free(q);
            }
            else
            {
                for (int i = 0; i < pos - 1; i++)
                {
                    p = q;
                    q = q->next;
                }
                cout << q->info << " node is deleted." << endl;
                p->next = q->next;
                free(q);
            }
        }
    }
    void circular_display()
    {
        nodetype *p = new nodetype();
        p = first;
        do
        {
            cout << p->info << "\t";
            p = p->next;
        } while (p != first);
        cout << endl;
    }
    void doubly_create()
    {
        int x;
        NODE *p = new NODE();
        cout << "Enter Value : ";
        cin >> x;
        p->info = x;
        if (f == NULL && l == NULL)
        {
            f = l = p;
            f->prev = NULL;
        }
        else
        {
            l->next = p;
            p->prev = l;
            l=p;
        }
        l->next = NULL;
        len++;
    }

    void doubly_delete(int pos)
    {
        NODE *p = new NODE();
        NODE *q = new NODE();
        NODE *r= new NODE();
        if (pos <= len)
        {
            q = f;
            if (pos == 1)
            {
                cout << q->info << " node is deleted." << endl;
                f = f->next;
                f->prev = NULL;
                free(q);
            }
            else if (pos == len)
            {
                while (q != NULL)
                {
                    p = q;
                    q = q->next;
                }
                cout << q->info << " node is deleted." << endl;
                l = p;
                p->next = NULL;
                free(q);
            }
            else
            {
                for(int i=0;i<pos-1;i++)
                {
                    p=q;
                    q=q->next;
                }
                r=q->next;
                cout<<q->info<<" node is deleted."<<endl;
                p->next=q->next;
                r->prev=p;
                free(q);
            }
        }
        else{
            cout<<"Position does not exist"<<endl;
        }
    }

    void doubly_display()
    {
        NODE *p = new NODE();
        p = f;
        while (p != NULL)
        {
            cout << p->info << "\t";
            p = p->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList L1;
    int ch, ch1;
    int pos;

    cout << "1.Singley Linked List\n2.Circular Linked List\n3.Doubley Linked List" << endl;
    cout << "Enter your choice : ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        while (1)
        {
            cout << "1.Create\n2.Delete node\n3.Display\n4.Exit" << endl;
            cin >> ch1;
            switch (ch1)
            {
            case 1:
                L1.single_create();
                break;
            case 2:
                cout << "Enter position of node to delete :";
                cin >> pos;
                L1.single_delete(pos);
            case 3:
                L1.single_display();
                break;
            case 4:
                return 0;
                break;
            default:
                cout << "Entered wrong choice ." << endl;
                break;
            }
        }
        break;

    case 2:
        while (1)
        {
            cout << "1.Create\n2.Delete node\n3.Display\n4.Exit" << endl;
            cin >> ch1;
            switch (ch1)
            {
            case 1:
                L1.circular_create();
                break;
            case 2:
                cout << "Enter position of node to delete :";
                cin >> pos;
                L1.circular_delete(pos);
                break;
            case 3:
                L1.circular_display();
                break;
            case 4:
                return 0;
                break;
            default:
                cout << "Entered wrong choice ." << endl;
                break;
            }
        }
        break;

    case 3:
        while (1)
        {
            cout << "1.Create\n2.Delete node\n3.Display\n4.Exit" << endl;
            cin >> ch1;
            switch (ch1)
            {
            case 1:
                L1.doubly_create();
                break;
                case 2:
                 cout << "Enter position of node to delete :";
                cin >> pos;
                L1.doubly_delete(pos);
                break;
            case 3:
                L1.doubly_display();
                break;
            case 4:
                return 0;
                break;
            default:
                cout << "Entered wrong choice ." << endl;
                break;
            }
        }
        break;
    default:
        cout << "Entered wrong choice." << endl;
        break;
    }

    return 0;
}