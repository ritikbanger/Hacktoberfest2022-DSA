class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    bool chk(vector<vector<int>>& board)
    {
        int k=1;
        for(int i=0;i<board.size();++i)
        {
            for(int j=0;j<board[0].size();++j)
            {
                if(board[i][j]!=k)
                {
                    return false;
                }
                k++;
                if(k==6)
                {
                    return true;
                }
            }
        }
        return true;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<pair<pair<int,int>,vector<vector<int>>>> q;
        for(int i=0;i<board.size();++i)
        {
            for(int j=0;j<board[0].size();++j)
            {
                if(board[i][j]==0)
                {
                    q.push({{i,j},board});
                    break;
                }
            }
        }
        int steps=0;
        set<vector<vector<int>>> st;
        st.insert(board);
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                auto temp=q.front();
                q.pop();
                int x=temp.first.first;
                int y=temp.first.second;
                if(chk(temp.second))
                {
                    return steps;
                }
                for(int i=0;i<4;++i)
                {
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx>=0 && ny>=0 && nx<board.size() && ny<board[0].size())
                    {
                        swap(temp.second[x][y],temp.second[nx][ny]);
                        if(st.find(temp.second)==st.end())
                        {
                            q.push({{nx,ny},temp.second});
                            st.insert(temp.second);
                        }
                        swap(temp.second[x][y],temp.second[nx][ny]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
