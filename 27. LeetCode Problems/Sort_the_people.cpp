class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
            map<int,string> m;
            int n=names.size();
            vector<string> v;
                    while(n>0)
                    { int x=*max_element(heights.begin(),heights.end());
                    for(int i=0;i<heights.size();i++)
                    {
                            if(heights[i]==x)
                            {
                                    heights[i]=-1;
                                    v.push_back(names[i]);
                                    continue;
                            }
                            if(x==-1)
                                    return v;
                    }
                     n--;
                    }
            return v;
    }
};
