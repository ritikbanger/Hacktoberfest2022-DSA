class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int , vector<pair<int,int>> > mp;
        vector<vector<int>> res;
        queue<pair<int,TreeNode*>> q;
        
        if(root == NULL)
            return res;
        
        int c = 0;
        q.push({0 , root});
        
        while(!q.empty())
        {
            int n = q.size();
            
            while(n--)
            {
                auto tmp = q.front();
                q.pop();
                
                mp[tmp.first].push_back({c , tmp.second->val});
                
                if(tmp.second->left)
                    q.push({tmp.first-1 , tmp.second->left});
                
                if(tmp.second->right)
                    q.push({tmp.first+1 , tmp.second->right});
            }
            
            c++;
        }
        
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            vector<pair<int,int>> tmp = it->second;
            vector<int> x;
            
            sort(tmp.begin() , tmp.end());
            
            for(int i = 0; i < tmp.size(); i++)
                x.push_back(tmp[i].second);
            
            res.push_back(x);
        }
        return res;
    }
};
