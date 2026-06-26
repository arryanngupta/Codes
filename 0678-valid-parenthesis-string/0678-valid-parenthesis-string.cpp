class Solution {
public:

    vector<vector<int>> dp;

    bool recFind(int idx,int cnt,string &s,int n){
        if(cnt<0) return false;
        if(idx==n) return (cnt==0);
        if(dp[idx][cnt]!=-1) return dp[idx][cnt];
        bool ans = false;
        if(s[idx]=='('){
            ans = recFind(idx+1,cnt+1,s,n);
        }
        else if(s[idx]==')'){
            ans = recFind(idx+1,cnt-1,s,n);
        }
        else{
            ans = ans||recFind(idx+1,cnt+1,s,n);
            ans = ans||recFind(idx+1,cnt,s,n);
            ans = ans||recFind(idx+1,cnt-1,s,n);
        }
        return dp[idx][cnt]=ans;
    }

    bool checkValidString(string s) {
        int n = s.size();
        dp.resize(n,vector<int> (n+1,-1));
        return recFind(0,0,s,n);
    }
};