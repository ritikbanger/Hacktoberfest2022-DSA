
struct Node{
  int isEnd;
    Node *links[26];
    vector<int> list;
    Node(){
        this->isEnd = -1;
        for(int i=0; i< 26; i++){
            links[i] = NULL;
        }
    }
};
class Trie {
    private:
    Node *root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int idx, string &word){
        Node *node = root;
        for(int i=0; i< word.size(); i++){
            int pos = (int )(word[i] - 'a');
            if(!node->links[pos]) {
                node->links[pos] = new Node();
            }
            node = node->links[pos];
            node->list.push_back(idx);
              
            } 
        
        node->isEnd = idx;
    }
    
    

    void dosum(vector<int> &ans){
        sum(root , ans);
    }

    void sum (Node *node ,vector<int> &ans){
        if(node == NULL) return ;
        int k = node->list.size();
        
        for(int i=0; i<k;i++){
            ans[node->list[i]] += k;
        }
        
        for(int i=0; i<26; i++ ){
            sum(node->links[i] , ans);    
        }
    }

};



class Solution {
public:
    
    
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie *trie = new Trie();
        int n = words.size();
        for(int i=0; i< n ;i++){
            trie->insert(i ,words[i]);
        }
        vector<int> ans(n, 0);
        trie->dosum(ans);
        return ans;
    }
};
