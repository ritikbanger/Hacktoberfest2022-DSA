#include <iostream>
using namespace std;
int nthFibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    int fib1 = nthFibonacci(n - 1);
    int fib2 = nthFibonacci(n - 2);
    int sum = fib1 + fib2;

    return sum;
}

int main()
{
    int n;
    cout << "Enter a Number : ";
    cin >> n;
    cout << "Fibonnaci : " << nthFibonacci(n);
    return 0;
}