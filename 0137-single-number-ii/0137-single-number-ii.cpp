class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(),ans = 0;
        int one = 0,two = 0;
        for(int i = 0; i<n; i++){
            one = (one^nums[i])&(~two);
            two = (two^nums[i])&(~one);
        }
        return one;
    }
};