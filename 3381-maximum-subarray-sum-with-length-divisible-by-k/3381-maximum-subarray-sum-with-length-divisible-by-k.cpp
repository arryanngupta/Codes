class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        vector<long long> prefixSum(n+1,0);
        for(int i = 0; i<n; i++){
            sum += nums[i];
            prefixSum[i+1] = sum;
        }
        long long ans = 0,maxi = -1e18;
        unordered_map<int,long long> mpp;
        for(int i = 0; i<n; i++){
            long long curr = prefixSum[i+1];
            if((i-k+1)>=0){
                long long currK = curr-prefixSum[i-k+1];
                mpp[i] = currK;
                if(mpp.find(i-k)!=mpp.end()){
                    if(mpp[i-k]>0){
                        mpp[i] += mpp[i-k];
                    }
                }
                maxi = max(maxi,mpp[i]);
            }            
        }
        return maxi;
    }
};