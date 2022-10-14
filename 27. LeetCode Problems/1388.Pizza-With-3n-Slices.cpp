class Solution {
    int dp[501][200] ;

    int getMax(vector<int>& slice , int m){
        int n = slice.size() ;

        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 1 ; j < m+1 ; j++){
                dp[i][j] = max(dp[i-1][j] , slice[i-1]+(i > 1 ? dp[i-2][j-1] : 0)) ;
            }
        }

        return dp[n][m] ;
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size()/3 ;
        for(int i = 0 ; i < slices.size() ; i++){
            for(int j = 0 ; j < k ; j++){
                dp[i][j] = INT_MIN ;
                
                if(j == 0) dp[i][j] = 0 ;
            }
        }

        auto slice1 = vector<int>(slices.begin() , slices.end()-1) ;
        auto slice2 = vector<int>(slices.begin()+1 , slices.end()) ;

        return max(getMax(slice1 , k) , getMax(slice2,k)) ;
    }
};
