#include <iostream>
using namespace std;

int main()
{
    int n;

    cin >> n;
    while (n--)
    {
        int d;
        cin >> d;

        int count = 0;
        int e;
        while (d > 0)
        {
            e = d % 10;
            d = d / 10;
            if (e == 4)
            {
                count++;
            }
        }
        cout << count << "\n";
    }
}