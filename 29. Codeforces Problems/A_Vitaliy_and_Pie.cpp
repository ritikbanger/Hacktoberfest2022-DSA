#include <iostream>
#include <iterator>
#include <cstring>
#include <map>
using namespace std;
int main(){
    map<char, int> m;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c = 0;
    for (int i = 0; i < s.length(); i = i + 2)
    {
        m[s[i]]++;
        if(m[tolower(s[i+1])]>0)
        {
            c++;
            m[tolower(s[i + 1])]--;
        }
    }
    cout << n-c-1 << endl;
}