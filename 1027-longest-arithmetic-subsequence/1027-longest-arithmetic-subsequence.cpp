class Solution {
public:

    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int base = 500,maxi = 0;
        vector<vector<int>> dp(n,vector<int> (1001,1));
        while(i<n){
            int j = i-1;
            while(j>=0){
                dp[i][nums[i]-nums[j]+base] = max(dp[i][nums[i]-nums[j]+base],dp[j][nums[i]-nums[j]+base]+1);
                maxi = max(maxi,dp[i][nums[i]-nums[j]+base]);
                j--;
            }
            i++;
        }
        return maxi;
    }
};