class Solution {
public:

    vector<vector<long long>> dp;

    long long recFind(int i,int j,string &s,string &t,int n,int m){
        if(j==m){
            return 1;
        }
        if(i==n){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        long long take = 0,notTake = 0;
        if(s[i]==t[j]){
            take = recFind(i+1,j+1,s,t,n,m);
        }
        notTake = recFind(i+1,j,s,t,n,m);
        return dp[i][j]=(take+notTake);
    }

    long long numOfSubsequences(string s) {
        int n = s.size();
        string str = "LCT";
        int m = str.size();
        dp.resize(n,vector<long long> (m,-1));
        long long curr = recFind(0,0,s,str,n,m);
        vector<tuple<long long, long long, long long>> left(n+1),right(n+1);
        vector<long long> LC(n+1),CT(n+1);
        int l = 0,c = 0,t = 0,lc = 0;
        for(int i = 0; i<n; i++){
            if(s[i]=='L'){
                l++;
            }
            else if(s[i]=='C'){
                c++;
                lc += l;
            }
            else if(s[i]=='T'){
                t++;
            } 
            left[i+1] = {l,c,t};
            LC[i+1] = lc;
        }
        l = 0,c = 0,t = 0;
        int ct = 0;
        for(int i = n-1; i>=0; i--){
            if(s[i]=='L'){
                l++;
            }
            else if(s[i]=='C'){
                ct += t;
                c++;
            }
            else if(s[i]=='T'){
                t++;
            } 
            right[i+1] = {l,c,t};
            CT[i+1] = ct;
        }
        long long maxi = 0;
        for(int i = 0; i<n; i++){
            auto [l,c,t] = right[i+1];
            maxi = max(maxi,CT[i+1]);
            l = get<0>(left[i]);
            maxi = max(maxi,1LL*l*t);
            c = get<1>(left[i]);
            t = get<2>(left[i]);
            maxi = max(maxi,LC[i+1]);            
        }
        maxi = max(maxi,LC[n]);
        return curr+maxi;
    }
};