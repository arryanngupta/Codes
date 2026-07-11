class Solution {
public:

    vector<vector<int>> adjList;
    vector<int> visited,deg;

    void dfs(int node,vector<int> &a){
        visited[node] = 1;
        a.push_back(node);
        for(auto it: adjList[node]){
            if(!visited[it]){
                dfs(it,a);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adjList.resize(n);
        deg.resize(n);
        for(auto it: edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
            deg[it[0]]++;
            deg[it[1]]++;
        }
        visited.resize(n);
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                vector<int> a;
                dfs(i,a);
                int flag = 0;
                for(auto it: a){
                    if(deg[it]!=a.size()-1){
                        flag = 1;
                        break;
                    }
                }
                if(flag==0) ans++;
            }
        }
        return ans;
    }
};