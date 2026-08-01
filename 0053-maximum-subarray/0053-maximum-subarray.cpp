class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int i = 0,j = 0,sum = 0,maxi = -1e9;
        while(j<n){
            sum += nums[j];
            maxi = max(maxi,sum);
            while(sum<0){
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return maxi;
    }
};