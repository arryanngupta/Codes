class Solution {
public:

    vector<vector<int>> adjList;
    vector<long long> visited;
    long long h;

    void dfs(int node,int par){
        if(par!=-1) visited[node] = visited[par]+1;
        h = max(h,visited[node]+1);
        for(auto it: adjList[node]){
            if(visited[it]==-1){
                dfs(it,node);
            }
        }
    }

    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        adjList.resize(n);
        for(int i = 1; i<n; i++){
            adjList[parent[i]].push_back(i);
        }
        visited.resize(n,-1);
        visited[0] = 0;
        h = 0;
        dfs(0,parent[0]);
        cout << h << endl;
        long long ans = 0;
        for(int i = 0; i<n; i++){
            ans += 1LL*nums[i]*(h-visited[i]);
        }
        return ans;
    }
};