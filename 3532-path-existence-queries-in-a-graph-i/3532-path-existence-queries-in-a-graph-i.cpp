class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> a(n);
        for(int i = 0; i<n; i++) a[i] = i; 
        for(int i = n-1; i>=0; i--){
            int ub = upper_bound(nums.begin(),nums.end(),nums[i]+maxDiff)-nums.begin()-1;
            a[i] = a[ub];
        }
        for(auto it: a){
            cout << it << " ";
        }
        cout << endl;
        vector<bool> ans;
        for(auto it: queries){
            int u = it[0],v = it[1];
            if(u>v) swap(u,v);
            if(v>a[u]) ans.push_back(false);
            else ans.push_back(true);
        }
        return ans;
    }
};