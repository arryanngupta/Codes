class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        pq.push(1);
        unordered_map<long long,int> mpp;
        long long ele = 0;
        while(n && !pq.empty()){
            n--;
            ele = pq.top();
            pq.pop();
            if(!mpp.count(2LL*ele)){
                pq.push(2LL*ele);
                mpp[2LL*ele]=1;
            }
            if(!mpp.count(3LL*ele)){
                pq.push(3LL*ele);
                mpp[3LL*ele]=1;
            }
            if(!mpp.count(5LL*ele)){
                pq.push(5LL*ele);
                mpp[5LL*ele]=1;
            }
        }
        return ele;
    }
};