#include <iostream>
#include <iterator>
#include <cstring>
#include <map>
// #include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int x[n], y[n];
    int i = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    int sum1 = 0,
        sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 += x[i];
    }
    for (int i = 0; i < n; i++)
    {
        sum2 += y[i];
    }
    int temp;
    int c = 0;
    if (sum1 % 2 != 0 and sum2 % 2 != 0)
    {
            for (int i = 0; i < n; i++)
            {
                if ((x[i] % 2 != 0 and y[i] % 2 == 0) or (x[i] % 2 == 0 and y[i] % 2 != 0))
                {
                    temp = x[i];
                    x[i] = y[i];
                    y[i] = temp;
                    sum1 = sum1 - temp + x[i];
                   
                    sum2 = sum2 - x[i] + y[i];
                    
                    if(sum1 % 2 == 0 and sum2 % 2 == 0)
                        c = 1;
                    else
                    {
                        c = -1;
                        
                    }
                    break;
                }
                else
                {
                    c = -1;
                }
            }
        }
    else if (sum1 % 2 == 0 and sum2 % 2 == 0)
    {
        c=0;
    }
    else
        c = -1;
    cout << c << endl;
}