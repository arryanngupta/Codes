class Solution {
public:

    vector<vector<vector<int>>> dp;

    int recFind(int i,int j,int flag,vector<int>& nums,int n){  
        if(i==j){
            return nums[i];
        }
        if(dp[i][j][flag]!=-1) return dp[i][j][flag];
        int ans = 0;
        if(flag){
            ans = nums[i]+recFind(i+1,j,0,nums,n);
            ans = max(ans,nums[j]+recFind(i,j-1,0,nums,n));
        }
        else{
            ans = recFind(i+1,j,1,nums,n);
            ans = min(ans,recFind(i,j-1,1,nums,n));
        }
        return dp[i][j][flag]=ans;
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,vector<vector<int>> (n,vector<int> (2,-1)));
        int total = accumulate(nums.begin(),nums.end(),0);
        int p1 = recFind(0,n-1,1,nums,n);
        return p1>=(total-p1);
    }
};