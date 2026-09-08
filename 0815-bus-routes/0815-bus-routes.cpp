class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        int n = routes.size(),maxi = 0;
        unordered_map<int,vector<int>> mpp;
        for(int i = 0; i<n; i++){
            for(auto it: routes[i]){
                mpp[it].push_back(i);
                maxi = max(maxi,it);
            }
        }
        if(!mpp.count(source) || !mpp.count(target)) return -1;
        priority_queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int> (maxi+1,1e9));
        for(auto it: mpp[source]){
            q.push({1,{it,source}});
            dist[it][source] = 1;
        }
        while(!q.empty()){
            int distance = q.top().first;
            int node = q.top().second.first;
            int nodeVal = q.top().second.second;
            q.pop();
            for(auto it: routes[node]){
                if(distance<dist[node][it]){
                    dist[node][it] = distance;
                    q.push({distance,{node,it}});
                    for(auto it1: mpp[it]){
                        if(distance+1<dist[it1][it]){
                            dist[it1][it] = distance+1;
                            q.push({distance+1,{it1,it}});
                        }
                    }
                }
            }
        }
        int mini = 1e9;
        for(auto it: mpp[target]){
            mini = min(mini,dist[it][target]);
        }
        return mini==1e9?-1:mini;
    }
};