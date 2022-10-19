/**Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally 
or vertically neighboring. The same letter cell may not be used more than once.
**/

bool dfs(vector<vector<char>>& v, string w,int i,int j,string ans="",int widx=0){
    if(ans==w) return true;
    if(i<0 || j<0 || 
       i>=v.size() || j>=v[0].size() ||
       v[i][j]!=w[widx] || v[i][j]=='#') return false;

    ans+=v[i][j];
    v[i][j]='#';
    bool ret=dfs(v,w,i+1,j,ans,widx+1) ||
        dfs(v,w,i,j+1,ans,widx+1) ||
        dfs(v,w,i-1,j,ans,widx+1) ||
        dfs(v,w,i,j-1,ans,widx+1);
    v[i][j] =w[widx];
    return ret;
}

bool exist(vector<vector<char>>& v, string w) {
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            if(v[i][j]==w[0]){
                if(dfs(v,w,i,j)) return true;
            }
        }
    }
    return false;
}
