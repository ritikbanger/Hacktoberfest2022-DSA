/*1
2 3
4 5 6
7 8 9 10*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of row : ";
    cin >> n;

    int i = 1;

    while (i <= n)
    {
        int j = 1;
        int value = i;
        while (j <= i)
        {
            cout << value<<" ";
            value = value + 1;
            j = j + 1;
        }
        cout << endl;
        i = i + 1;
    }
    return 0;
}

/* I think my way of approch is better than previous one, it is more clear and easily understandable :)*/