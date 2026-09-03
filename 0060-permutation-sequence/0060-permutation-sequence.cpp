class Solution {
public:

    vector<int> fact;

    void find(int n){
        fact[0] = 1;
        for(int i = 1; i<n; i++){
            fact[i] = fact[i-1]*i;
        }
    }

    string getPermutation(int n, int k) {
        fact.resize(n+1);
        find(n);
        string ans = "";
        vector<int> a(n+1);
        while(k && ans.size()<n){
            for(int i = 1; i<=n; i++){
                if(a[i]) continue;
                int ways = fact[n-ans.size()-1];
                if(ways>=k){
                    ans += (i+'0');
                    a[i] = 1;
                    break;
                }
                else{
                    k -= ways;
                }
            }
        }
        if(ans.size()<n){
            for(int i = 1; i<=n; i++){
                if(a[i]==0){
                    ans += (i+'0');
                    break;
                }
            }
        }
        return ans;
    }
};