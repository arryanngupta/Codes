class Solution {
public:

    vector<vector<long long>> dp;

    long long recFind(int i,int j,int m, int n, vector<vector<int>>& waitCost){
        if(i==m-1 && j==n-1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long ans = 1e18;
        if(j+1<n){
            long long cost = (i==m-1 && j+1==n-1)?0:waitCost[i][j+1];
            ans = cost+1LL*(i+1)*(j+2)+recFind(i,j+1,m,n,waitCost);
        }
        if(i+1<m){
            long long cost = (i+1==m-1 && j==n-1)?0:waitCost[i+1][j];
            ans = min(ans,cost+1LL*(i+2)*(j+1)+recFind(i+1,j,m,n,waitCost));
        }
        return dp[i][j]=ans;
    }

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        dp.resize(m,vector<long long> (n,-1));
        return 1+recFind(0,0,m,n,waitCost);
    }
};