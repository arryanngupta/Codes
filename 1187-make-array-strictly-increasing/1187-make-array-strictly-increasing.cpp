class Solution {
public:

    vector<vector<int>> dp;

    int recFind(int idx,int prev,vector<int>& arr1, vector<int>& arr2,int n,int m){
        if(idx>=n) return 0;
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        int ans = 1e9;
        if(idx==0){
            ans = recFind(idx+1,-1,arr1,arr2,n,m);
            for(int i = 0; i<m; i++){
                ans = min(ans,1+recFind(idx+1,i,arr1,arr2,n,m));
            }
        }
        else{
            int prevEle = prev==-1?arr1[idx-1]:arr2[prev];
            if(arr1[idx]>prevEle){
                ans = recFind(idx+1,-1,arr1,arr2,n,m);
            }
            int ub = upper_bound(arr2.begin(),arr2.end(),prevEle)-arr2.begin();
            if(ub<m) ans = min(ans,1+recFind(idx+1,ub,arr1,arr2,n,m));
        }
        return dp[idx][prev+1]=ans;
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(),m = arr2.size();
        sort(arr2.begin(),arr2.end());
        dp.resize(n,vector<int> (m+1,-1));
        int ans = recFind(0,-1,arr1,arr2,n,m);
        return ans>=1e9?-1:ans;
    }
};