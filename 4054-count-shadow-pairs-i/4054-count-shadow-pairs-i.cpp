class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> mpp;
        for(int i = 0; i<n; i++){
            mpp[nums[i]].push_back(i);
        }
        vector<int> nse(n,n);
        stack<int> st;
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            if(!st.empty()){
                nse[i] = st.top();
            }
            st.push(i);
        }
        long long ans = 0;
        for(int i = 0; i<n; i++){
            int lb1 = upper_bound(mpp[nums[i]].begin(),mpp[nums[i]].end(),i)-mpp[nums[i]].begin();
            int idx = nse[i];
            int lb2 = lower_bound(mpp[nums[i]].begin(),mpp[nums[i]].end(),idx)-mpp[nums[i]].begin();
            int w = nse[i]-i-1;
            ans += w-(lb2-lb1);
        }
        return ans;
    }
};