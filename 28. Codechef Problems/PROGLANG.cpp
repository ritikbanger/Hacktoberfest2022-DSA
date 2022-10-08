#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int arr[6];

        for (int j = 0; j < 6; j++)
        {
            cin >> arr[j];
        }

        int req1 = arr[0], req2 = arr[1];
        if ((req1 == arr[2] && req2 == arr[3]) || (req1 == arr[3] && req2 == arr[2]))
        {
            cout << "1" << endl;
        }
        else if ((req1 == arr[4] && req2 == arr[5]) || (req1 == arr[5] && req2 == arr[4]))
        {
            cout << "2" << endl;
        }
        else
        {
            cout << "0" << endl;
        }
        }
    return 0;
}