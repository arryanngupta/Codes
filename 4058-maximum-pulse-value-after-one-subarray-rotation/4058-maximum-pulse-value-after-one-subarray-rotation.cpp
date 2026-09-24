class Solution {
public:
    long long maxValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(i%2==0) ans+=nums[i];
            else ans-=nums[i];
        }
        long long maxPos = -1e18,maxNeg = 0,sum = 0;
        long long mini = 1e18;
        for(int i = 0; i<n; i++){
            if(i%2==0){
                sum += nums[i];
                mini = min(mini,sum-maxPos);
                maxPos = max(maxPos,sum);
            }
            else{
                sum -= nums[i];
                mini = min(mini,sum-maxNeg);
                maxNeg = max(maxNeg,sum);
            }
        }
        if(mini<0) ans += -2LL*(mini);
        return ans;
    }
};