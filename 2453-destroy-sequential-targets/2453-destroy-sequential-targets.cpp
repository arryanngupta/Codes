class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mpp;
        for(int i = 0; i<n; i++){
            mpp[nums[i]%space]++;
        }
        int maxi = 0;
        for(auto it: mpp){
            maxi = max(maxi,it.second);
        }
        for(auto it: nums) if(mpp[it%space]==maxi) return it;
        return nums[0];
    }
};