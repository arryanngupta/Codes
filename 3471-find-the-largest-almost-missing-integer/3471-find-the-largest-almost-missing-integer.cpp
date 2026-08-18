class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i = 0; i<=n-k; i++){
            unordered_set<int> st;
            for(int j = i; j<n; j++){
                if(j-i+1>k) break;
                st.insert(nums[j]);
            }
            for(auto it: st){
                mpp[it]++;
            }
        }
        int maxi = -1;
        for(auto it: mpp){
            if(it.second==1) maxi = max(maxi,it.first);
        }
        return maxi;
    }
};