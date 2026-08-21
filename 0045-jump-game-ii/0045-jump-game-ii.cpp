class Solution {
public:

    vector<int> dp;

    int recFind(int idx,vector<int>& nums,int n){
        if(idx==(n-1)) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int mini = 1e9;
        for(int i = 1; i<=nums[idx]; i++){
            if(idx+i>=n) break;
            mini = min(mini,1+recFind(idx+i,nums,n));
        }
        return dp[idx]=mini;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,-1);
        return recFind(0,nums,n);
    }
};