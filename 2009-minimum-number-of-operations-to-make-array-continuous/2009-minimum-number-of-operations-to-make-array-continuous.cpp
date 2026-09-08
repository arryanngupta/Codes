class Solution {
public:


    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        set<int> st;
        for(auto it: nums) st.insert(it);
        for(auto it: st) temp.push_back(it);
        int i = 0,j = i,ans = 1e9,len = temp.size();
        while(j<len){
            while(j<len && temp[j]-temp[i]<n) j++;
            int cnt = j-i;
            ans = min(ans,n-cnt);
            i++;
            j++;
        }
        return ans;
    }
};