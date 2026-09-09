class Solution {
public:

    set<vector<int>> st;

    void recFind(int mask,vector<int> a,vector<int>& nums,int n){
        if(mask==((1<<n)-1)){
            st.insert(a);
            return ;
        }
        for(int i = 0; i<n; i++){
            if((mask&(1<<i))==0){
                int updMask = mask|(1<<i);
                a.push_back(nums[i]);
                recFind(updMask,a,nums,n);
                a.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> a;
        recFind(0,a,nums,n);
        return vector<vector<int>>(st.begin(),st.end());
    }
};