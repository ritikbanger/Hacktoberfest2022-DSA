// { Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
	int modInverse(int a, int m)
	{
		int m0 = m;
		int y = 0, x = 1;

		if (m == 1)
			return 0;

		while (a > 1) {
			// q is quotient
			int q = a / m;
			int t = m;

			// m is remainder now, process same as
			// Euclid's algo
			m = a % m, a = t;
			t = y;

			// Update y and x
			y = x - q * y;
			x = t;
		}

		// Make x positive
		if (x < 0)
			x += m0;

		return x;
	}

};

// { Driver Code Starts.

int main()
{
	int T;

	//taking testcases
	cin >> T;
	while (T--)
	{
		int a, m;

		//taking input a and m
		cin >> a >> m;
		Solution ob;
		//calling function modInverse()
		cout << ob.modInverse(a, m) << endl;
	}
	return 0;
} // } Driver Code End
