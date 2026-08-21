class Solution {
public:
    bool isUgly(int n) {
        if(n<=0) return false;
        for(int i = 2; 1LL*i*i<=n; i++){
            if(n%i==0){
                if(i!=2 && i!=5 && i!=3) return false;
                while(n && n%i==0){
                    n = n/i;
                }
            }
        }
        if(n>1 && n!=2 && n!=5 && n!=3) return false;
        return true;
    }
};