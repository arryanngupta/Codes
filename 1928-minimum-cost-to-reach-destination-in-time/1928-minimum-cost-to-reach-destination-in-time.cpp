class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int,int>>> adjList(n);
        for(auto it: edges){
            adjList[it[0]].push_back({it[1],it[2]});
            adjList[it[1]].push_back({it[0],it[2]});
        }
        vector<vector<int>> dist(n,vector<int> (maxTime+1,1e9));
        dist[0][0] = passingFees[0];
        priority_queue< pair<pair<int,int>,int>,
        vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>> > pq;
        pq.push({{dist[0][0],0},0});
        while(!pq.empty()){
            int distance = pq.top().first.first,t = pq.top().first.second;
            int node = pq.top().second;
            pq.pop();
            if(distance>dist[node][t]) continue;
            for(auto it: adjList[node]){
                int adjNode = it.first,wt = it.second;
                if(t+wt<=maxTime && distance+passingFees[adjNode]<dist[adjNode][t+wt]){
                    dist[adjNode][t+wt] = distance+passingFees[adjNode];
                    pq.push({{dist[adjNode][t+wt],t+wt},adjNode});
                }
            }
        }
        int mini = 1e9;
        for(int i = 0; i<=maxTime; i++){
            mini = min(mini,dist[n-1][i]);
        }
        if(mini==1e9) return -1;
        return mini;
    }
};