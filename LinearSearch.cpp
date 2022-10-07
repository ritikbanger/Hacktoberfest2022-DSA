#include <iostream>
using namespace std;

bool search(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{

        int arr[10] = {10, 2, 245, 7, 56, 56, 542, 3, 12, 45};
        // Whether 1 is present or not?
        cout << "Enter the key" << endl;
        int key;
        cin >> key;
        bool found = search(arr, 10, key);
        if (found)
        {
            cout << "Key is present" << endl;
        }
        else
        {
            cout << "Key is absent" << endl;
        }
