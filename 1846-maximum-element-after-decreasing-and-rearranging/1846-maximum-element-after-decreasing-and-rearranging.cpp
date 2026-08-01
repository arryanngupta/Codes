class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0,ans = 0;
        sort(arr.begin(),arr.end());
        for(int i = 0; i<n; i++){
            cnt++;
            ans = min(cnt,arr[i]);
            cnt = ans;
        }
        return ans;
    }
};