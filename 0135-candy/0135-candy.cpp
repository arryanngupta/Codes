class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> a(n,1);
        for(int i = 1; i<n; i++){
            if(ratings[i]>ratings[i-1]){
                a[i] = a[i-1]+1;
            }
        }
        int right = 1,ans = 0;
        for(int i = n-1; i>=0; i--){
            if(i==n-1){
                ans += a[i];
                continue;
            }
            if(ratings[i]>ratings[i+1]){
                right++;
            }
            else right = 1;
            ans += max(a[i],right);
        }
        return ans;
    }
};