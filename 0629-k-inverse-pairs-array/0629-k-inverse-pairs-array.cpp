class Solution {
public:

    vector<vector<int>> dp;
    int mod = (int)(1e9+7);

    int recFind(int n,int k){
        if(n==0) return 0;
        if(k==0) return 1;
        if(dp[n][k]!=-1) return dp[n][k];
        int ans = 0;
        for(int inv = 0; inv<=min(n-1,k); inv++){
            ans = (ans+recFind(n-1,k-inv))%mod;
        }
        return dp[n][k]=ans;
    }

    int kInversePairs(int n, int k) {
        // dp.resize(n+1,vector<int> (k+1,-1));
        // return recFind(n,k);

        dp.resize(n+1,vector<int> (k+1,0));
        for(int K = 0; K<=k; K++){
            dp[0][K]=0;
        }
        for(int N = 1; N<=n; N++) dp[N][0] = 1;

        for(int N = 1; N<=n; N++){
            for(int K = 1; K<=k; K++){
                int ans = 0;
                for(int inv = 0; inv<=min(N-1,K); inv++){
                    ans = (ans+dp[N-1][K-inv])%mod;
                }
                dp[N][K]=ans;
            }
        }
        return dp[n][k];
    }
};