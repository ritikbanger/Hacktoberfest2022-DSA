class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
    int first = INT_MAX, second = INT_MAX;
    
    for(auto &el : nums){
        if(el <= first) first = el;
        else if(el <= second) second = el;
        else return 1;
    }
    
    return 0;
}
};
