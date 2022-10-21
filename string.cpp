// CPP program to find smallest
// number to find smallest number
// with N as sum of digits and
// divisible by 10^N.
#include <bits/stdc++.h>
using namespace std;

void digitsNum(int N)
{
	// If N = 0 the string will be 0
	if (N == 0)
		cout << "0\n";
	
	// If n is not perfectly divisible
	// by 9 output the remainder
	if (N % 9 != 0)
		cout << (N % 9);
	
	// Print 9 N/9 times
	for (int i = 1; i <= (N / 9); ++i)
		cout << "9";
	
	// Append N zero's to the number so
	// as to make it divisible by 10^N
	for (int i = 1; i <= N; ++i)
		cout << "0";
	
	cout << "\n";
}

// Driver Code
int main()
{
	int N = 5;
	cout << "The number is : ";
	digitsNum(N);
	return 0;
}
