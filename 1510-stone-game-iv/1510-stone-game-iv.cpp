class Solution {
public:

    vector<vector<int>> dp;

    int recFind(int n,int turn){
        if(n==0) return turn;
        int sqRoot = sqrt(n);
        if(1LL*sqRoot*sqRoot== n) return !turn;
        if(dp[n][turn]!=-1) return dp[n][turn];
        int ans = turn;
        for(int i = 1; 1LL*i*i<=n; i++){
            int rem = 1LL*i*i;
            int left = n-rem;
            int sqRoot = sqrt(left);
            if(1LL*sqRoot*sqRoot== left) continue;
            if(turn){
                ans = ans && recFind(left,0);
            }
            else ans = ans || recFind(left,1);
        }
        return dp[n][turn]=ans;
    }

    bool winnerSquareGame(int n) {
        dp.resize(n+1,vector<int> (2,-1));
        return recFind(n,0);
    }
};