class Solution {
public:

    vector<vector<vector<int>>> dp;

    int recFind(int idx,int m,int flag,vector<int>& piles,int n){
        if(idx>=n) return 0;
        if(dp[idx][m][flag]!=-1) return dp[idx][m][flag];
        int sum = 0,ans = flag?0:1e9;
        for(int x = 1; x<=2*m && (idx+x)<=n; x++){
            sum += piles[idx+x-1];
            if(flag) ans = max(ans,sum+recFind(idx+x,min(n,max(m,x)),!flag,piles,n));
            else ans = min(ans,recFind(idx+x,min(n,max(m,x)),!flag,piles,n));
        }
        return dp[idx][m][flag]=ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.resize(n,vector<vector<int>> (n+1,vector<int> (2,-1)));
        return recFind(0,1,1,piles,n);
    }
};