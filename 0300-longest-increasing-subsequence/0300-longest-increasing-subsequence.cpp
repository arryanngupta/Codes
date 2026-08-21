class Solution {
public:

    vector<vector<int>> dp;

    int recFind(int idx,int prev,vector<int>& nums,int n){
        if(idx>=n) return 0;
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        int take = 0,notTake = 0;
        if(prev==-1 || nums[idx]>nums[prev]){
            take = 1+recFind(idx+1,idx,nums,n);
        }
        notTake = recFind(idx+1,prev,nums,n);
        return dp[idx][prev+1]=max(take,notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,vector<int> (n,-1));
        return recFind(0,-1,nums,n);
    }
};