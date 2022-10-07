class MyCalendarThree {
    map<int,int>m;
    int maxi = 0;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int val = 0;
        for(auto x:m){
            val+=x.second;
            maxi = max(maxi,val);
        }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */