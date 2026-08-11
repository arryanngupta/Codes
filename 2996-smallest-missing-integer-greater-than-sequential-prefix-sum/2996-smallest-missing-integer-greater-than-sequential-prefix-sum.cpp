class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0],n = nums.size();
        unordered_map<int,int> mpp;
        mpp[nums[0]]++;
        int i = 1;
        while(i<n && (nums[i]-nums[i-1]==1)){
            mpp[nums[i]]++;
            sum += nums[i];
            i++;
        }
        while(i<n) mpp[nums[i++]]++;
        while(mpp.count(sum)){
            sum++;
        }
        return sum;
    }
};