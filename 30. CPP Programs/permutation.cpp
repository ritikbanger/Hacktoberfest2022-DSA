#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    char str[]={'a','b','c'};
    bool v=next_permutation(str,str+3);
    cout<<str;
}