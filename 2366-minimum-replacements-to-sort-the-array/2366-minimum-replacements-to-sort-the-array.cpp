class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        int val = nums[n-1];
        long long ans = 0;
        for(int i = n-2; i>=0; i--){
            if(val<nums[i]){
                int pieces = ceil(nums[i]/(double)val);
                ans += pieces-1;
                val = nums[i]/pieces;
            }
            else{
                val = nums[i];
            }
        }
        return ans;
    }
};