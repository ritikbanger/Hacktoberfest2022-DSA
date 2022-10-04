#pragma GCC optimize("Ofast")
#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <iterator>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void aman()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


int main(int argc, char* argv[]) {
	aman();

	string s = "1100011";
    int ans=0,count=1;
    if(s.size() == 0) return ans;
	for(int i=0; i<s.size()-1; i++) {
		if(s[i] == s[i+1]) {
			count++;
			if(count == 3) {
				ans++;
				count = 1;
				i++;
			}
		} else {
			count = 1;
		}
	}
	cout << ans << endl;
   return 0;
}
