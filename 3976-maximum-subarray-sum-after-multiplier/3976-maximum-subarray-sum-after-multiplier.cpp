class Solution {
public:

    vector<vector<vector<long long>>> dp;

    long long recFind(int idx,int op,int flag,vector<int>& nums, int k,int n){
        if(idx>=n){
            if(flag) return 0;
            return -1e18;
        }
        if(dp[idx][op][flag]!=-1) return dp[idx][op][flag];
        long long take = -1e18,notTake = -1e18;
        if(op==0){
            take = nums[idx]+recFind(idx+1,op,1,nums,k,n);
            if(nums[idx]>0) take = max(take,1LL*nums[idx]*k+recFind(idx+1,1,1,nums,k,n));
            else take = max(take,nums[idx]/k+recFind(idx+1,2,1,nums,k,n));
        }
        else if(op==1){
            take = 1LL*nums[idx]*k+recFind(idx+1,op,1,nums,k,n);
            take = max(take,nums[idx]+recFind(idx+1,3,1,nums,k,n));
        }
        else if(op==2){
            take = nums[idx]/k+recFind(idx+1,op,1,nums,k,n);
            take = max(take,nums[idx]+recFind(idx+1,3,1,nums,k,n));
        }
        else{
            take = nums[idx]+recFind(idx+1,op,1,nums,k,n);
        }
        if(!flag){
            notTake = max(notTake,recFind(idx+1,0,0,nums,k,n));
        }
        else notTake = 0;
        return dp[idx][op][flag]=max(take,notTake);
    }

    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        dp.resize(n,vector<vector<long long>> (4,vector<long long> (2,-1)));
        return recFind(0,0,0,nums,k,n);
    }
};



