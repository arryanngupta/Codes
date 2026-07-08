class Solution {
public:

    vector<vector<int>> adjList,ans;
vector<int> visited,low,steps;

    int t;

    void dfs(int node,int parent){
        visited[node] = 1;
        low[node] = t;
        steps[node] = t;
        t++;
        for(auto it: adjList[node]){
            if(it==parent) continue;
            if(!visited[it]){
                dfs(it,node);
                low[node]=min(low[node],low[it]);
                if(low[it]>steps[node]) ans.push_back({node,it});
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adjList.assign(n,{});
        for(auto it: connections){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        visited.assign(n,0);
        low.assign(n,0);
        steps.assign(n,0);
        ans.clear();
        t = 1;
        for(int i = 0; i<n; i++){
            if(!visited[i]) dfs(i,-1);
        }
        return ans;
    }
};