#include <iostream>
using namespace std;

int main(){
    int t, n, k;
    cin >> t;

    for(int i = 1; i <= t; i++){
        cin >> n >> k;

        int total_marksof_bob = (n-k);
        cout << total_marksof_bob << endl;
    }
    return 0;
}