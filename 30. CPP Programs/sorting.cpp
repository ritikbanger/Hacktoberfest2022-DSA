/* Name - Satyam Gupta
    Roll no -32
    CST
    SORTING*/

#include <iostream>
#define MAX 100
using namespace std;

class sorting
{
    int a[MAX], lb=0,ub=n-1;

public:
int n;
    void get()
    {
        cout << "Enter size of array : ";
        cin >> n;
        cout << "Enter the elements of array : " << endl;
        for (int i = 0; i < n; i++)
            cin >> a[i];
    }

    void BubbleSort()
    {
        int temp = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (a[j] > a[j + 1])
                {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }

    void sel_sort()
    {
        int pos, min = 0;

        for (int i = 0; i < n - 1; i++)
        {
            min = a[i];
            pos = i;
            for (int j = i + 1; j < n; j++)
            {
                if (min > a[j])
                {
                    min = a[j];
                    pos = j;
                }
            }
            if (pos != i)
            {
                a[pos] = a[i];
                a[i] = min;
            }
        }
    }

    void InsertionSort()
    {
        int i, j, temp = 0;
        for (i = 1; i < n; i++)
        {
            temp = a[i];
            j = i - 1;
            while (j >= 0 && temp < a[j])
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = temp;
        }
    }

    void quick_sort(int lb, int ub)
    {
        int i = lb, j = ub, key = a[lb], temp = 0;
        if (lb >= ub)
            return;
        while (i < j)
        {
            while (key >a[i] && i < j)
                i++;
            while (key < a[j])
                j--;
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        quick_sort(lb,j-1);
        quick_sort(j+1,ub);
    }

    void display()
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << "\t";
    }
};

int main()
{
    int ch;
    sorting s1;
    s1.get();
    cout << "Array before sorting : " << endl;
    s1.display();
    cout<<endl;
    cout << "1.Bubble sort \n2.Selection Sort \n3.Insertion Sort\n4.Quick Sort\n5.Exit" << endl;
    cout << "Enter valid choice : " << endl;
    cin >> ch;

    switch (ch)
    {
    case 1:
        s1.BubbleSort();
        break;
    case 2:
        s1.sel_sort();
        break;
    case 3:
        s1.InsertionSort();
        break;
        case 4:
        s1.quick_sort(0,(s1.n)-1);
        break;
        case 5:
        return 0;
    default:
        cout << "Entered choice is wrong" << endl;
        break;
    }
    cout << "Array after sorting : " << endl;
    s1.display();
    return 0;
}