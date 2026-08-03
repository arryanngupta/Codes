class Solution {
public:

    vector<vector<vector<int>>> dp;

    int recFind(int i,int j,int flag,vector<int>& piles){
        if(i==j){
            if(flag) return piles[i];
            return 0;
        }
        if(dp[i][j][flag]!=-1) return dp[i][j][flag];
        int ans = 0;
        if(flag){
            ans = piles[i]+recFind(i+1,j,!flag,piles);
            ans = max(ans,piles[j]+recFind(i,j-1,!flag,piles));
        }
        else{
            ans = recFind(i+1,j,!flag,piles);
            ans = min(ans,recFind(i,j-1,!flag,piles));
        }
        return dp[i][j][flag]=ans;
    }

    bool stoneGame(vector<int>& piles) {
        int total = accumulate(piles.begin(),piles.end(),0);
        int n = piles.size();
        dp.resize(n,vector<vector<int>> (n,vector<int> (2,-1)));
        int alice = recFind(0,n-1,1,piles);
        int bob = total-alice;
        return alice>bob;
    }
};