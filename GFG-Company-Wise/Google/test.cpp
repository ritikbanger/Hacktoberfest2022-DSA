#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    long long res = 0;
    vector<int> prefix = {-1, 0, 1, 2};
    unordered_map<int, int> mp;
    for (int i = 0; i < prefix.size(); ++i)
    {
        int target = 0 - prefix[i];
        auto it = mp.find(target);
        if (it != mp.end())
            res += i - it->second + 1;
        else
            res += target < 0 ? i + 1 : 0;
        if (mp.find(prefix[i]) == mp.end())
            mp[prefix[i]] = i;
    }

    cout << res << "\n";
    return 0;
}