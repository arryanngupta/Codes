class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<=3) return 0;
        sort(nums.begin(),nums.end());
        int mini = nums[n-1]-nums[0];
        for(int i = 0; i<=3; i++){
            mini = min(mini,nums[n-1]-nums[i]);
            mini = min(mini,nums[n-1-i]-nums[0]);
        }
        mini = min(mini,nums[n-2]-nums[2]);
        mini = min(mini,nums[n-3]-nums[1]);
        return mini;
    }
};