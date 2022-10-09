#include<bits/stdc++.h>
using namespace std;



 vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
          int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int,int>>all;
      
        for(int i = 0;i<n-1;i++){
            all.push_back({i,0});
        }
          for(int i = 0;i<m;i++){
            all.push_back({n-1,i});
        }
        int k = 0;
        vector<vector<int>>sol;
          for(auto x : all){
             vector<int>temp;
            int i = x.first;
            int j = x.second;
              
            while(i>=0 && j<m){
               temp.push_back(matrix[i][j]);
                i--;
                j++;
            }
             if(k%2 != 0){
                 reverse(temp.begin(),temp.end());
                 sol.push_back(temp);
             }else{
                 sol.push_back(temp);
             }
             k++;
        }
        vector<int>ans;
        for(auto x : sol){
            for(auto y : x){
                ans.push_back(y);
            }
        }
        return ans;
        
    }
 

void print(vector<int>&arr){
	for(auto x : arr){
	
			cout<<x<<" ";
	}
}


int main(){
    vector<vector<int>>matrix;
    int n;
    cout<<"No. of rows of matrix : ";
    cin>>n;
    for(int i = 0;i<n;i++){
    	vector<int>temp;
    	for(int j = 0;j<n;j++){
    		int val ;
    		cin>>val;
    		temp.push_back(val);
		}
		matrix.push_back(temp);
	}
    vector<int>ans;
	ans = findDiagonalOrder(matrix);
	cout<<"Diagonal Traversal Order   : \n";
	print(ans);
	return 0;
}
