class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int len = edges.size();
        vector<vector<pair<int,double>>>adjList(n);
        for(int i = 0; i<len; i++){
            adjList[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adjList[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double> dist(n,0);
        dist[start_node] = 1;
        priority_queue< pair<double,int>> pq;
        pq.push({dist[start_node],start_node});
        while(!pq.empty()){
            double distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(distance>dist[node]) continue;
            for(auto it: adjList[node]){
                int adjNode = it.first;
                double wt = it.second;
                double val = distance*wt;
                if(val>dist[adjNode]){
                    dist[adjNode] = val;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist[end_node];
    }
};