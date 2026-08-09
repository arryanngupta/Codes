class Solution {
public:

    vector<vector<pair<int,int>>> adjList;
    vector<int> visited,ans;

    int dfs(int node){
        visited[node] = 1;
        int ans = 0;
        for(auto it: adjList[node]){
            if(!visited[it.first]){
                ans += it.second+dfs(it.first);
            }
        }
        return ans;
    }

    void dfs2(int node){
        visited[node] = 1;
        for(auto it: adjList[node]){
            if(!visited[it.first]){
                if(it.second==0){
                    ans[it.first] = ans[node]+1;
                }
                else{
                    ans[it.first] = ans[node]-1;
                }
                dfs2(it.first);
            }
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        adjList.resize(n);
        for(auto it: edges){
            adjList[it[0]].push_back({it[1],0});
            adjList[it[1]].push_back({it[0],1});
        }
        visited.resize(n);
        ans.resize(n);
        ans[0] = dfs(0);
        visited.assign(n,0);
        dfs2(0);
        return ans;
    }
};