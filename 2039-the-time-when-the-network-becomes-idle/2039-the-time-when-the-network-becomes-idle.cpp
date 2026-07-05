class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> adjList(n);
        for(auto it: edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        vector<int> dist(n,1e9);
        dist[0] = 0;
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>> > pq;
        pq.push({0,0});
        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(distance>dist[node]) continue;
            for(auto it: adjList[node]){
                if(distance+1<dist[it]){
                    dist[it] = distance+1;
                    pq.push({dist[it],it});
                }
            }
        }
        int maxi = 0;
        for(int i = 1; i<n; i++){
            int d = dist[i];
            int gap = 2*d-1;
            int resend = gap/patience[i];
            maxi = max(maxi,2*d+(resend*patience[i]));
        }
        return maxi+1;
    }
};