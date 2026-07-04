class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adjList(n);
        for(auto it: roads){
            adjList[it[0]-1].push_back({it[1]-1,it[2]});
            adjList[it[1]-1].push_back({it[0]-1,it[2]});
        }
        priority_queue< pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>> > pq;
        pq.push({1e9,0});
        vector<int> dist(n,1e9);
        while(!pq.empty()){
            int score = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it: adjList[node]){
                int adjNode = it.first,wt = it.second;
                int cost = min(wt,score);
                if(cost<dist[adjNode]){
                    dist[adjNode] = cost;
                    pq.push({cost,adjNode});
                }
            }
        }
        return dist[n-1];
    }
};