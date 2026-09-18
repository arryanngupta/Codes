class Solution {
public:

    vector<int> dp;

    int recFind(int idx,vector<vector<int>>& offers,int n){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take = 0,notTake = 0;
        int ub = upper_bound(offers.begin(),offers.end(),vector<int>{offers[idx][1],INT_MAX,INT_MAX})-offers.begin();
        take = offers[idx][2]+recFind(ub,offers,n);
        notTake = recFind(idx+1,offers,n);
        return dp[idx]=max(take,notTake);
    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end());
        int len = offers.size();
        dp.resize(len,-1);
        return recFind(0,offers,len);
    }
};