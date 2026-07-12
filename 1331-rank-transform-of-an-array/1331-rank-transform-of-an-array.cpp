class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>> > pq;
        for(int i = 0; i<n; i++){
            pq.push({arr[i],i});
        }
        vector<int> ans(n);
        int rank = 1,i=0;
        while(!pq.empty()){
            int ele = pq.top().first,idx = pq.top().second;
            pq.pop();
            ans[idx] = rank;
            if(!pq.empty() && pq.top().first!=ele) rank++;
        }
        return ans;
    }
};