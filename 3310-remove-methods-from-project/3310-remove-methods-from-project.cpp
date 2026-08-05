class Solution {
public:

    vector<vector<int>> adjList;
    vector<int> visited;

    bool dfs(int node,int type){
        visited[node] = type;
        for(auto it: adjList[node]){
            if(visited[it]==0){
                if(!dfs(it,type)) return false;
            }
            else if(visited[it]!=type) return false;
        }
        return true;
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        adjList.resize(n);
        for(auto it: invocations){
            adjList[it[0]].push_back(it[1]);
        }
        visited.resize(n);
        dfs(k,2);
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                if(!dfs(i,1)){
                    vector<int> ans(n);
                    for(int i = 0; i<n; i++) ans[i] = i;
                    return ans;
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i<n; i++){
            if(visited[i]==1) ans.push_back(i);
        }
        return ans;
    }
};