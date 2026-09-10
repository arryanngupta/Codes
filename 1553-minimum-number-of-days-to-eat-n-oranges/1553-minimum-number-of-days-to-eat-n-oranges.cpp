class Solution {
public:

    unordered_map<int,int> mpp;

    int recFind(int n){
        if(n==0) return 0;
        if(mpp.count(n)) return mpp[n];
        int ans = 2e9;
        if(n%2==0){
            ans = 1+recFind(n-n/2);
        }
        else ans = 1+recFind(n-1);
        if(n%3==0){
            ans = min(ans,1+recFind(n-2*(n/3)));
        }
        else ans = min(ans,n%3+recFind(n-n%3));
        return mpp[n]=ans;
    } 

    int minDays(int n) {
        return recFind(n);
    }
};