class Solution {
public:

    vector<vector<int>> adjList,dp;

    int recFind(int node,int par,int cnt,vector<int>& coins,int k,int n){
        if(dp[node][cnt]!=-1) return dp[node][cnt];
        int val = coins[node]/(1<<cnt);
        int op1 = val-k,op2 = val/2;
        for(auto it: adjList[node]){
            if(it==par) continue;
            op1 += recFind(it,node,cnt,coins,k,n);
            op2 += recFind(it,node,min(19,cnt+1),coins,k,n);
        }
        return dp[node][cnt]=max(op1,op2);
    }

    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        adjList.resize(n);
        for(auto it: edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        dp.resize(n,vector<int> (20,-1));
        return recFind(0,-1,0,coins,k,n);
    }
};