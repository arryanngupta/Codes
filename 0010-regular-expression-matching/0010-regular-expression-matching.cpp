class Solution {
public:

    vector<vector<int>> dp;

    int recFind(int i,int j,string &p, string &s,int n,int m){
        if(i==n && j==m) return 1;
        if(i==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        if(j<m && (i+1==n || (i+1<n && p[i+1]!='*'))){
            if(p[i]==s[j] || p[i]=='.') ans |= recFind(i+1,j+1,p,s,n,m);
        }
        else{
            if(i+1<n && p[i+1]=='*'){
                ans |= recFind(i+2,j,p,s,n,m);
                if(j<m && (p[i]==s[j] || p[i]=='.')) ans |= recFind(i,j+1,p,s,n,m);
            }
        }
        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        int n = p.size(),m = s.size();
        dp.resize(n,vector<int> (m+1,-1));
        return recFind(0,0,p,s,n,m);
    }
};