class Solution {
public:

    vector<vector<int>> dp;

    int recFind(int i,int j,string &s,int n){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int idx = i;
        while(idx+1<=j && s[idx]==s[idx+1]){
            idx++;
        }
        int ans = 1+recFind(idx+1,j,s,n);
        int p = idx+1;
        while(p<=j){
            if(s[p]==s[i]){
                ans = min(ans,recFind(idx+1,p-1,s,n)+recFind(p,j,s,n));
                while(p<=j && s[p]==s[i]) p++;
            }
            else p++;
        }
        return dp[i][j]=ans;
    }

    int strangePrinter(string s) {
        int n = s.size();
        dp.resize(n,vector<int> (n,-1));
        return recFind(0,n-1,s,n);
    }
};