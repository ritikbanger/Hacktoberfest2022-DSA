// Written by saurav1207 
/*
Output like this :-
1234554321
1234**4321
123****321
12******21
1********1

*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of row : ";
    cin >> n;

    int i = 1;
    while (i <= n)
    {
        // Print First Triangle
        int j = 1;
        while (j <= n - i + 1)
        {
            cout << j;
            j = j + 1;
        }
        // Print second triangle
        j = 1;
        while (j <= (i - 1) * 2)
        {
            cout << "*";
            j = j + 1;
        }

        // Print Third triangle
        j = n - i + 1;
        while (j >= 1)
        {
            cout << j;
            j = j - 1;
        }
        i = i + 1;
        cout << endl;
    }
    return 0;
}