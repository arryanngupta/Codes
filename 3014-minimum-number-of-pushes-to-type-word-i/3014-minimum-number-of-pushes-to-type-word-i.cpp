class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size(),ans = 0,cnt = 1;
        while(n){
            int sub = min(n,8);
            ans += sub*cnt;
            cnt++;
            n -= sub;
        }
        return ans;
    }
};