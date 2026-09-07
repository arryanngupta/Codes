class Solution {
public:

    vector<vector<int>> dp;

    int recFind(int idx,int swap,vector<int>& nums1, vector<int>& nums2,int n){
        if(idx>=n) return 0;
        if(dp[idx][swap+1]!=-1) return dp[idx][swap+1];
        int ans = 1e9;
        if(swap==-1){
            ans = recFind(idx+1,0,nums1,nums2,n);
            ans = min(ans,1+recFind(idx+1,1,nums1,nums2,n));
        }
        else if(!swap){
            if(nums1[idx]>nums1[idx-1] && nums2[idx]>nums2[idx-1]){
                ans = recFind(idx+1,swap,nums1,nums2,n);
            }
            if(nums1[idx]>nums2[idx-1] && nums2[idx]>nums1[idx-1]){
                ans = min(ans,1+recFind(idx+1,1,nums1,nums2,n));
            }
        }
        else{
            if(nums1[idx]>nums2[idx-1] && nums2[idx]>nums1[idx-1]){
                ans = recFind(idx+1,0,nums1,nums2,n);
            }
            if(nums1[idx]>nums1[idx-1] && nums2[idx]>nums2[idx-1]){
                ans = min(ans,1+recFind(idx+1,1,nums1,nums2,n));
            }
        }
        return dp[idx][swap+1]=ans;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        dp.resize(n,vector<int> (3,-1));
        return recFind(0,-1,nums1,nums2,n);
    }
};