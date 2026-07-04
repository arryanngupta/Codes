class Solution {
public:

    int mod = (int)(1e9+7);
    int dp[102][102][102][2][2];

    int recFind(int i,int j,int k,int flag1,int flag2,string &word1, string &word2, string &target,int n,int m,int t){
        if(k==t) return (flag1 && flag2);
        if((i>=n&&flag1==0) || (j>=m&&flag2==0)) return 0;
        if(dp[i][j][k][flag1][flag2]!=-1) return dp[i][j][k][flag1][flag2];
        int ans = 0;
        for(int first = i; first<n; first++){
            if(word1[first]==target[k]) ans = (ans+recFind(first+1,j,k+1,1,flag2,word1,word2,target,n,m,t))%mod;
        }
        for(int second = j; second<m; second++){
            if(word2[second]==target[k]) ans = (ans+recFind(i,second+1,k+1,flag1,1,word1,word2,target,n,m,t))%mod;
        }
        return  dp[i][j][k][flag1][flag2]=ans%mod;
    }
    
    int interleaveCharacters(string word1, string word2, string target) {
        int n = word1.size(),m = word2.size(),t = target.size();
        memset(dp,-1,sizeof(dp));
        return recFind(0,0,0,0,0,word1,word2,target,n,m,t);
    }
};