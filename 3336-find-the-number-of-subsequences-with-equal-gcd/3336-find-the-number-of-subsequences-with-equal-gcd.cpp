class Solution {
public:

    int mod = (int)(1e9+7);
    int dp[200][201][201][2];

    int recFind(int idx,int gcd1,int gcd2,int flag,vector<int>& nums,int n){
        if(idx==n) return (flag && gcd1==gcd2);
        if(dp[idx][gcd1][gcd2][flag]!=-1) return dp[idx][gcd1][gcd2][flag];
        int ans = 0;
        ans = (ans+recFind(idx+1,__gcd(gcd1,nums[idx]),gcd2,1,nums,n))%mod;
        ans = (ans+recFind(idx+1,gcd1,__gcd(gcd2,nums[idx]),1,nums,n))%mod;
        ans = (ans+recFind(idx+1,gcd1,gcd2,flag,nums,n))%mod;
        return dp[idx][gcd1][gcd2][flag]=ans;
    }

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return recFind(0,0,0,0,nums,n);
    }
};