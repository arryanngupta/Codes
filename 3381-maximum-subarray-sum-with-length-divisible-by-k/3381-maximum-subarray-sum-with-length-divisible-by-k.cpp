class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> a(n,-1e18),prefixSum(n+1);
        long long sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            prefixSum[i+1] = sum;
        }
        long long maxi = -1e18;
        for(int i = 0; i<n; i++){
            long long currK = 0;
            if(i-k+1>=0) currK = prefixSum[i+1]-prefixSum[i-k+1];
            else{
                continue;
            }
            a[i] = currK;
            if(i-k>=0 && a[i-k]>0) a[i] += a[i-k];
            maxi = max(maxi,a[i]);
        }
        return maxi;
    }
};