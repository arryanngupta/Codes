class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long sum = 0;
        int n = beans.size();
        sort(beans.begin(),beans.end());
        vector<long long> prefixSum(n+1);
        for(int i = 0; i<n; i++){
            sum += beans[i];
            prefixSum[i+1] = sum;
        }
        long long mini = 1e18;
        for(int i = 0; i<n; i++){
            long long l = prefixSum[i];
            long long r = sum-prefixSum[i+1];
            long long subt = 1LL*(n-i-1)*beans[i];
            r -= subt;
            long long op = l+r;
            mini = min(mini,op);
        }
        return mini;
    }
};