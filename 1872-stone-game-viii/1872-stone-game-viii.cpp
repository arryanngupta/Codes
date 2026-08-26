class Solution {
public:

    vector<int> prefixSum,dp;

    int recFind(int idx,int n){
        if(idx==n-1) return prefixSum[n];
        if(dp[idx]!=INT_MAX) return dp[idx];
        int take = prefixSum[idx+1]-recFind(idx+1,n);
        int notTake = recFind(idx+1,n);
        return dp[idx]=max(take,notTake);
    }

    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        prefixSum.resize(n+1,0);
        prefixSum[1] = stones[0];
        for(int i = 1; i<n; i++){
            prefixSum[i+1] = prefixSum[i]+stones[i];
        }
        dp.resize(n,INT_MAX);
        return recFind(1,n);
    }
};