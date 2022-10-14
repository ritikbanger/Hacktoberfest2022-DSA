int fact(int val){
    int s=1;
    if(val==1 || val==0)
        return 1;
    else{
        while(val>0){
            s=(s% 1000003)*(val% 1000003);
            val--;
        }
    }
    return s;
}
int Solution::findRank(string A) {
    long long int sum=0;
    for(int i=0;i<A.length();i++){
        long long int cnt=0;
        for(int j=i+1;j<A.length();j++){
            if(A[j]<A[i]){
                // cout<<A[i]<<" "<<A[j-1]<<endl;
                cnt++;
            }
        }
        sum=sum+(fact(A.length()-i-1)*cnt)% 1000003;
    }
    return (sum+1)% 1000003;
}
