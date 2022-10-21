#include <iostream>
using namespace std;
int fibo(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return fibo(n - 2) + fibo(n - 1);
    }
}

int main()
{
    int n;
    cout << "enter n ";
    cin >> n;
    cout << "the fibonacci sequence is ";
    for (int i = 0; i <= n; i++)
    {
        int k = fibo(i);
        cout << k << " ";
    }
}
