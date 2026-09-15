class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0,j = 0;
        unordered_map<int,int> mpp;
        long long val = 0,ans = 0;
        while(j<n){
            mpp[nums[j]]++;
            if(mpp[nums[j]]==1){
                j++;
                continue;
            }
            long long of = mpp[nums[j]]-1,nf = of+1;
            long long ov = (1LL*(of-1)*(of))/2;
            long long nv = (1LL*(nf-1)*(nf))/2;
            val = val-ov+nv;
            while(val>=k){
                ans += n-j;
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0){
                    i++;
                    continue;
                }
                int nf = mpp[nums[i]],of = nf+1;
                long long ov = (1LL*(of-1)*(of))/2;
                long long nv = (1LL*(nf-1)*(nf))/2;
                val = val-ov+nv;
                i++;
            }
            j++;
        }
        return ans;
    }
};