class Solution {
public:

    int mod = (int)(1e9+7);
    vector<int> fact;

    int power(int a,int b){
        if(b==0) return 1;
        int half = power(a,b/2);
        int total = (1LL*half*half)%mod;
        if(b%2!=0) total = (1LL*total*a)%mod;
        return total;
    }

    void find(int n){
        fact.resize(n+1);
        fact[0] = 1;
        for(int i = 1; i<=n; i++){
            fact[i] = (1LL*fact[i-1]*i)%mod;
        }
    }

    int ncr(int n,int r){
        if(r<0 || r>n) return 0;
        int a = fact[n];
        int b = (1LL*fact[r]*fact[n-r])%mod;
        int modInv = power(b,mod-2);
        int ans = (1LL*a*modInv)%mod;
        return ans;
    }
    
    int countValidSequences(int n, int k) {
        find(n);
        int total = ncr(n-1,k-1);
        if((n+k)%2!=0) return total;
        // 0 -> ncr(n-1+k,k-1)
        // 1 -> ncr(n'-1+k,k-1) where n' = n-k
        // so i have used 1 wla formula in both total and odd .
        int odd = ncr((n-k)/2-1+k,k-1);
        return (total-odd+mod)%mod;
    }
};