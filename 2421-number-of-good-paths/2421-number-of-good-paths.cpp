class Solution {
public:

    vector<int> parent,rank;

    int findUPar(int node){
        if(parent[node]==node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void findUnion(int u,int v){
        int ulp_u = findUPar(u),ulp_v = findUPar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_v]>rank[ulp_u]) swap(ulp_u,ulp_v);
        if(rank[ulp_u]==rank[ulp_v]) rank[ulp_u]++;
        parent[ulp_v] = ulp_u;
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        parent.resize(n);
        for(int i = 0; i<n; i++) parent[i] = i;
        rank.resize(n,0);
        vector<vector<int>> adjList(n);
        for(auto it: edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        map<int,vector<int>> mpp;
        for(int i = 0; i<n; i++){
            mpp[vals[i]].push_back(i);
        }
        int ans = 0;
        vector<int> a(n);
        for(auto it: mpp){
            int v = it.first;
            for(auto node: it.second){
                a[node] = 1;
            }
            for(auto node: it.second){
                for(auto adjNode: adjList[node]){
                    if(a[adjNode]) findUnion(node,adjNode);
                }
            }
            unordered_map<int,int> mpp2;
            for(auto node: it.second){
                mpp2[findUPar(node)]++;
            }
            for(auto it1: mpp2){
                int no = it1.second;
                if(no==1) continue;
                ans += (1LL*no*(no-1))/2;
            }
        }
        return n+ans;
    }
};