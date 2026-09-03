class Solution {
public:

    vector<vector<vector<long long>>> dp;

    long long recFind(int i,int p1,int p2,int n,vector<vector<int>>& cost){
        if(i<0) return 0;
        if(dp[i][p1+1][p2+1]!=-1) return dp[i][p1+1][p2+1];
        long long ans = 1e18;
        for(int c1 = 0; c1<3; c1++){
            for(int c2 = 0; c2<3; c2++){
                if(c1==c2 || c1==p1 || c2==p2) continue;
                ans = min(ans,0LL+cost[i][c1]+cost[n-i-1][c2]+recFind(i-1,c1,c2,n,cost));
            }
        }
        return dp[i][p1+1][p2+1]=ans;
    }

    long long minCost(int n, vector<vector<int>>& cost) {
        dp.resize(n,vector<vector<long long>> (4,vector<long long> (4,-1)));
        return recFind(n/2-1,-1,-1,n,cost);
    }
};