class Solution {
public:

    vector<long long> prefixSum;
    vector<vector<int>> dp;

    int recFind(int i,int j,vector<int>& stoneValue,int n){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long left = 0,total = prefixSum[j+1]-prefixSum[i];
        int ans = 0,maxi = 0;
        for(int idx = i; idx<j; idx++){
            left += stoneValue[idx];
            long long right = total-left;
            if(left<right){
                ans = left+recFind(i,idx,stoneValue,n);
            }
            else if(right<left){
                ans = right+recFind(idx+1,j,stoneValue,n);
            }
            else{
                ans = left+max(recFind(i,idx,stoneValue,n),recFind(idx+1,j,stoneValue,n));
            }
            maxi = max(maxi,ans);
        }
        return dp[i][j]=maxi;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        prefixSum.resize(n+1);
        dp.resize(n,vector<int> (n,-1));
        long long sum = 0;
        for(int i = 0; i<n; i++){
            sum += stoneValue[i];
            prefixSum[i+1] = sum;
        }
        return recFind(0,n-1,stoneValue,n);
    }
};