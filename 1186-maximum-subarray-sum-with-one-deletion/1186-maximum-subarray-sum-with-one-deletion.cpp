class Solution {
public:

    vector<vector<vector<int>>> dp;

    int recFind(int idx,int flag,int op,vector<int>& arr,int n){
        if(idx>=n){
            if(flag) return 0;
            return -1e9;
        }
        if(dp[idx][flag][op]!=-1) return dp[idx][flag][op];
        int take = -1e9,notTake = -1e9;
        take = arr[idx]+recFind(idx+1,1,op,arr,n);
        if(!flag || op){
            int updOp = flag?0:1;
            notTake = recFind(idx+1,flag,updOp,arr,n);
        }
        else notTake = 0;
        return dp[idx][flag][op]=max(take,notTake);
    }

    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        dp.resize(n,vector<vector<int>>(2,vector<int> (2,-1)));
        return recFind(0,0,1,arr,n);
    }
};