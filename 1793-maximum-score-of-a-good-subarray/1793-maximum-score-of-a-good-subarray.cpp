class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        long long maxi = nums[k];
        int mini = nums[k],n = nums.size();
        int i = k,j = k;
        while(i!=0 || j!=n-1){
            if(j+1>=n || (i-1>=0 && nums[i-1]>=nums[j+1])){
                i--;
                mini = min(mini,nums[i]);
                maxi = max(maxi,1LL*mini*(j-i+1));
            }
            else if(i-1<0 || (j+1<n && nums[j+1]>nums[i-1])){
                j++;
                mini = min(mini,nums[j]);
                maxi = max(maxi,1LL*mini*(j-i+1));
            }
        }
        return (int) maxi;
    }
};