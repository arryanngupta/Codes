class Solution {
public:

    int jump(vector<int>& nums) {
        int n = nums.size();
        int i = 0,maxi = 0,maxi2 = 0,ans = 0;
        while(i<n){
            if(i>maxi) return -1;
            if(i>maxi2){
                ans++;
                maxi2 = maxi;
            }
            maxi = max(maxi,i+nums[i]);
            i++;
        }
        return ans;
    }
};