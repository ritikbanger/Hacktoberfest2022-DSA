#include <bits/stdc++.h>
using namespace std;

bool targetsum(int arr[],int n,int sum){
int dp[n+1][sum+1];
for(int i=0;i<=n;i++){
    for(int j=0;j<=sum;j++){
        if(i==0 && j>0){
            dp[i][j]=0;
}
        else if(j==0){
        dp[i][j]=1;
}

        else if(arr[i-1]>j){
        dp[i][j]=dp[i-1][j];
}
        else 
        dp[i][j]= dp[i-1][j] || dp[i-1][j-arr[i-1]];
    }
}

return dp[n][sum];


}

int main (){
    int arr[5]={5,2,5,1,4};
    int sum=14;
    if(targetsum(arr,5,sum)){
        cout<<"true";
    }else
    cout<<"false";
    
}