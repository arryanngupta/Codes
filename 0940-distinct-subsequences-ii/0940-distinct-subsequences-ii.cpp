class Solution {
public:

    int mod = (int)(1e9+7);

    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> dp(n),freq(26,-1);
        dp[0] = 2;
        freq[s[0]-'a']=0;
        for(int i = 1; i<n; i++){
            if(freq[s[i]-'a']==-1){
                dp[i] = (2LL*dp[i-1])%mod;
            }
            else{
                int last = freq[s[i]-'a'];
                if(last>0) dp[i] = (2LL*dp[i-1]-dp[last-1]+mod)%mod;
                else dp[i] = (2LL*dp[i-1]-1+mod)%mod;
            }
            freq[s[i]-'a']=i;
        }
        return (dp[n-1]-1+mod)%mod;
    }
};