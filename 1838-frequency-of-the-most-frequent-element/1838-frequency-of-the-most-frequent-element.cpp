class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int j = n-1,i = j,maxi = 0;
        while(i>=0){
            int diff = nums[j]-nums[i];
            if(k>=diff){
                k -= diff;
                maxi = max(maxi,j-i+1);
                i--;
            }
            else{
                k += 1LL*(j-i-1)*(nums[j]-nums[j-1]);
                j--;
            }
        }
        return maxi;
    }
};