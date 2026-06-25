class Solution {
public:
    int dp[2001][2001][2];
    int mod = (int)(1e9+7);
    int zigZagArrays(int n, int l, int r) {
        int l1 = 1;
        int r1 = r-l+1;
        for(int prev = 1; prev<=r1; prev++){
            dp[n][prev][0] = 1;
            dp[n][prev][1] = 1;
        }
        int prefixSum1[2002];
        int prefixSum2[2002];
        for(int idx = n-1; idx>=0; idx--){
           prefixSum1[0] = prefixSum1[1] = 0;
            prefixSum2[0] = prefixSum2[1] = 0;
            int sum = 0,sum2 = 0;
            for(int val = 1; val<=r1; val++){
                sum = (sum+dp[idx+1][val][0])%mod;
                prefixSum1[val+1] = sum;
                sum2 = (sum2+dp[idx+1][val][1])%mod;
                prefixSum2[val+1] = sum2;
            }
            for(int prev = r1; prev>=1; prev--){
                int ans1 = 0,ans0 = 0;
                ans1 = (ans1+prefixSum1[prev])%mod;
                ans0 = (ans0+prefixSum2[r1+1]-prefixSum2[prev+1]+mod)%mod;
                dp[idx][prev][1]=ans1;
                dp[idx][prev][0] = ans0;
            }
        }
        int asc = 0,dsc = 0;
        for(int i = l1; i<=r1; i++){
            asc = (asc+dp[1][i][1])%mod;
            dsc = (dsc+dp[1][i][0])%mod;
        }
        int ans = (asc+dsc)%mod;
        return ans;
    }
};