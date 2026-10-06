class Solution {
public:

    vector<vector<vector<vector<long long>>>> dp;

    long long recFind(int idx,int even,int flag,int temp,vector<int>& nums,int n){
        if(idx>=n){
            if(temp) return 0;
            return -1e18;
        }
        if(dp[idx][even][flag][temp]!=-1) return dp[idx][even][flag][temp];
        long long take = -1e18,notTake = -1e18;
        if(even){
            take = nums[idx]+recFind(idx+1,0,flag,1,nums,n);
            take = max(take,1LL*nums[idx]);
        }
        else{
            take = -nums[idx]+recFind(idx+1,1,flag,1,nums,n);
            take = max(take,-1LL*nums[idx]);
        }
        if(flag || !temp){
            int updFlag = temp==0?flag:!flag;
            notTake = recFind(idx+1,even,updFlag,temp,nums,n);
        }
        return dp[idx][even][flag][temp]=max(take,notTake);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,vector<vector<vector<long long>>> (2,vector<vector<long long>> (2,vector<long long> (2,-1))));
        return recFind(0,1,1,0,nums,n);
    }
};
