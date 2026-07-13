class Solution {
public:

    int minTaps(int n, vector<int>& ranges) {
        int i = 0,maxi = 0,maxEnd = 0,ans = 0;
        vector<int> a(n+1);
        for(int i = 0; i<=n; i++){
            int l = max(0,i-ranges[i]);
            int r = min(n,i+ranges[i]);
            a[l] = max(a[l],r);
        }
        while(i<=n){
            if(i>maxEnd) return -1;
            if(i>maxi){
                maxi = maxEnd;
                ans++;
            }
            if(maxi>=n) return ans;
            cout << maxi << endl;
            int flag = 0;
            while(i<=maxi){
                maxEnd = max(maxEnd,a[i]);
                i++;
                flag = 1;
            }
            if(flag==0) i++;
        }
        return ans;
    }
};