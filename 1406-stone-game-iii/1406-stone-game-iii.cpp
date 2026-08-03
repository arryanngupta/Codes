class Solution {
public:

    vector<vector<int>> dp;

    int recFind(int i,int flag,vector<int>& piles,int n){
        if(i>=n){
            return 0;
        }
        if(dp[i][flag]!=-1) return dp[i][flag];
        int ans = flag?-1e9:1e9;
        if(flag){
            int sum = 0;
            for(int x = 1; x<=3 && i+x<=n; x++){
                sum += piles[i+x-1];
                ans = max(ans,sum+recFind(i+x,!flag,piles,n));
            }
        }
        else{
            for(int x = 1; x<=3 && i+x<=n; x++){
                ans = min(ans,recFind(i+x,!flag,piles,n));
            }
        }
        return dp[i][flag]=ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.resize(n,vector<int> (2,-1));
        int total = accumulate(stoneValue.begin(),stoneValue.end(),0);
        int alice = recFind(0,1,stoneValue,n);
        int bob = total-alice;
        if(alice>bob) return "Alice";
        if(alice<bob) return "Bob";
        return "Tie";
    }
};