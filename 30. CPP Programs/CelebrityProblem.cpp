#include<iostream>
#include<deque>

using namespace std;

int main(){
    
    int n;
    cin>>n;

    int ** matrix = new int*[n];

    for(int i=0;i<n;i++){
        matrix[i] = new int[n];

        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }

    deque<int> stackk;

    for(int i=0;i<n;i++){
        stackk.push_back(i);
    }

    while(stackk.size()!=1){
        int top1 = stackk.front();
        stackk.pop_front();
        int top2 = stackk.front();
        stackk.pop_front();

        if(matrix[top1][top2]==1){
            stackk.push_front(top2);
        }else{
            stackk.push_front(top1);
        }
    }

    int last1 = stackk.front();

    bool isCeleb = true;

    for(int i=0;i<n;i++){

        if(i==last1){
            continue;
        }

        if(matrix[i][last1]==0){
            isCeleb = false;
            break;
        }

        if(matrix[last1][i]==1){
            isCeleb = false;
            break;
        }
    }

    if(isCeleb){
        cout<<"Celebrity is : "<<last1<<endl;
    }else{
        cout<<"No Celebrity found!!"<<endl;
    }


    return 0;
}

