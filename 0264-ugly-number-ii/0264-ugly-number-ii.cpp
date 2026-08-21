class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> a(n+1);
        a[1] = 1;
        int i2 = 1,i3 = 1,i5 = 1;
        for(int i = 2; i<=n; i++){
            long long l1 = a[i2]*2;
            long long l2 = a[i3]*3;
            long long l3 = a[i5]*5;
            a[i] = min({l1,l2,l3});
            if(a[i]==l1) i2++;
            if(a[i]==l2) i3++;
            if(a[i]==l3) i5++;
        }
        return a[n];
    }
};