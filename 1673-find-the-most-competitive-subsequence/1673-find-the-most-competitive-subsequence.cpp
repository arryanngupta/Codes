class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int> st;
        int i = 0,K = k;
        while(i<n){
            int flag = 0;
            while(!st.empty() && st.top()>nums[i]){
                if(n-i<=k){
                    flag = 1;
                    break;
                }
                st.pop();
                k++;
            }
            if(flag) break;
            if(st.empty() || nums[i]>=st.top() && st.size()<K){
                st.push(nums[i]);
                k--;
            }
            i++;
        }
        while(i<n){
            st.push(nums[i++]);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};