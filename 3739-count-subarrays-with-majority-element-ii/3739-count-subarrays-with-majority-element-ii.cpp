class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<long long,long long> mpp;
        long long sum = 0,ans = 0,val = 0;
        mpp[0] = 1;
        for(auto it: nums){
            if(it==target){
                val += mpp[sum];
                sum++;
            }
            else{
                sum--;
                val -= mpp[sum];
            }
            mpp[sum]++;
            ans += val;
        }
        return ans;
    }
};