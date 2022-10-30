 
#include <iostream>
using namespace std;
void HollowDiamond(int n)
{
// ******************
// ********  ********
// *******    *******
// ******      ******
// *****        *****
// ****          ****
// ***            ***
// **              **
// *                *
// *                *
// **              **
// ***            ***
// ****          ****
// *****        *****
// ******      ******
// *******    *******
// ********  ********
// ******************
 
 
int count=0,space=n-1;
    for (int row = 1; row <= 2*n-1; row++)
    {
        row<=n ? count++ : count--;
        row<=n ? space-- : space++;
        if(row==n)
        continue;
        for (int i = 0; i <=space; i++)
        {
            cout<<"*";
        }
        
        
        for (int col = 1; col <count; col++)
        {
            cout<<" ";
        }
        for (int col = 1; col <count; col++)
        {
            cout<<" ";
        }

        for (int i = 0; i <=space; i++)
        {
            cout<<"*";
        }
         cout<<"\n";
    }
}
int main()
{
        int n=10;
	  HollowDiamond(n);
	return 0;
}
 
