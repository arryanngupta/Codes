class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        map<int,int> mpp;
        for(auto it: nums) mpp[it]++;
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
        vector<int> ans;
        for(int i = mini; i<=maxi; i++){
            if(mpp[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};