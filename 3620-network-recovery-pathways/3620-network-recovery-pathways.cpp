class Solution {
public:

    vector<vector<pair<int,int>>> adjList;

    bool check(int mid,vector<bool>& online, long long k){
        int n = online.size();
        vector<long long> dist(n,k+1);
        dist[0] = 0;
        priority_queue<pair<pair<int,int>,int>,
        vector<pair<pair<int,int>,int>>,
        greater<pair<pair<int,int>,int>> > pq;
        pq.push({{0,1e9},0});
        long long mini = 1e9;
        while(!pq.empty()){
            long long distance = pq.top().first.first,score = pq.top().first.second,node = pq.top().second;
            mini = min(mini,score);
            pq.pop();
            if(distance>dist[node]) continue;
            for(auto it: adjList[node]){
                long long adjNode = it.first,wt = it.second;
                if(online[adjNode] && wt>=mid && distance+wt<dist[adjNode]){
                    dist[adjNode] = distance + wt;
                    pq.push({{dist[adjNode],min(mini,wt)},adjNode});
                }
            }
        }
        if(dist[n-1]==k+1) return 0;
        return (mini>=mid);
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        adjList.resize(n);
        int low = 1e9,high = 0;
        for(auto it: edges){
            adjList[it[0]].push_back({it[1],it[2]});
            low = min(low,it[2]);
            high = max(high,it[2]);
        }
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(mid,online,k)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};