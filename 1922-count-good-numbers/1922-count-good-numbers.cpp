class Solution {
public:

    int mod = (int)(1e9+7);

    int power(int a,long long b){
        if(b==0) return 1;
        int half = power(a,b/2);
        int total = (1LL*half*half)%mod;
        if(b%2!=0) total = (1LL*total*a)%mod;
        return total;
    }

    int countGoodNumbers(long long n) {
        long long e = (n+1)/2;
        long long o = n-e;
        int ans = (1LL*power(5,e)*power(4,o))%mod;
        return ans;
    }
};