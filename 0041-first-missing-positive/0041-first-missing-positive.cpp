class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        long long n = nums.size();
        if(n==1 && nums[0]==1) return 2;
        else if(n==1) return 1;
        long long i = 0;
        while(i<n){
            long long idx = nums[i];
            if(idx<1 || idx>n){
                i++;
                continue;
            }
            while(idx>0 && idx<=n && nums[idx-1]!=INT_MAX){
                long long temp = nums[idx-1];
                nums[idx-1] = INT_MAX;
                idx = temp;
            }
            i++;
        }
        for(int i = 0; i<n; i++){
            if(nums[i]!=INT_MAX) return i+1;
        }
        return n+1;
    }
};