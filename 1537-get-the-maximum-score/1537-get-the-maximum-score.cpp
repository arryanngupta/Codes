class Solution {
public:

    unordered_map<int,int> mpp1,mpp2;
    int mod = (int)(1e9+7);
    vector<vector<long long>> dp;

    long long recFind(int idx,int flag,vector<int>& nums1, vector<int>& nums2,int n,int m){
        if(idx==n && flag==0) return 0;
        if(idx==m && flag) return 0;
        if(dp[idx][flag]!=-1) return dp[idx][flag];
        long long ans = 0;
        if(flag==0){
            if(mpp2.count(nums1[idx])){
                ans = (nums1[idx]+recFind(idx+1,flag,nums1,nums2,n,m));
                int i = mpp2[nums1[idx]];
                ans = max(ans,(0LL+nums1[idx]+recFind(i+1,!flag,nums1,nums2,n,m)));
            }
            else{
                ans = (nums1[idx]+recFind(idx+1,flag,nums1,nums2,n,m));
            }
        }
        else{
            if(mpp1.count(nums2[idx])){
                ans = (nums2[idx]+recFind(idx+1,flag,nums1,nums2,n,m));
                int i = mpp1[nums2[idx]];
                ans = max(ans,(0LL+nums2[idx]+recFind(i+1,!flag,nums1,nums2,n,m)));
            }
            else{
                ans = (nums2[idx]+recFind(idx+1,flag,nums1,nums2,n,m));
            }
        }
        return dp[idx][flag]=ans;
    }

    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m = nums2.size();
        dp.resize(max(n,m),vector<long long> (2,-1));
        for(int i = 0; i<n; i++){
            mpp1[nums1[i]]=i;
        }
        for(int i = 0; i<m; i++){
            mpp2[nums2[i]]=i;
        }
        long long ans1 = recFind(0,0,nums1,nums2,n,m);
        long long ans2 = recFind(0,1,nums1,nums2,n,m);
        return max(ans1%mod,ans2%mod);
    }
};