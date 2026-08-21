class Solution {
public:

    vector<int> dp;

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,1);
        int maxi = 0;
        for(int i = 0; i<n; i++){
            int j = i-1;
            while(j>=0){
                if(nums[i]>nums[j]) dp[i] = max(dp[i],dp[j]+1);
                j--;
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};