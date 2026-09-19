class FreqStack {
public:
    unordered_map<int,int> mpp;
    priority_queue<pair<pair<int,int>,int>> pq;
    int t;
    FreqStack() {
        t = 0;
    }
    
    void push(int val) {
        mpp[val]++;
        t++;
        pq.push({{mpp[val],t},val});
    }
    
    int pop() {
        int val = pq.top().second;
        mpp[val]--;
        pq.pop();
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */