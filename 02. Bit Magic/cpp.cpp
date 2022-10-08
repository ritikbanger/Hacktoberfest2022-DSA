#include <iostream>

using namespace std;

int find_zeros(int n){
    int ans=0;
    int p=5;
    while((n/p)>0)
    {
        ans+=(n/p);
        p=p*5;

    }
    return ans;
}
int main(){
    
    long long int a;
    cin>>a;
    cout<<find_zeros(a)<<endl;

}
