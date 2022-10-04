#include <bits/stdc++.h>
using namespace std;
int maxSubArray(int a[],int n){
    int maxS=INT_MIN;
    int curS=0;

    for(int i=0;i<n;i++){
        curS+=a[i];
    
        if(curS>maxS){
            maxS=curS;
        }
        if(curS<0){
            curS=0;
        }    
    }
    return maxS;

}

int main(){
    int a[]={-1,-2,-3,-4};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<maxSubArray(a,n);
}
