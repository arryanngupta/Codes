class Solution {
public:

    int check(int mid,vector<int>& nums,int p){
        int i = 0,cnt = 0;
        int n = nums.size();
        while(i<n-1){
            if(nums[i+1]-nums[i]<=mid){
                i += 2;
                cnt++;
            }
            else{
                i++;
            }
        }
        return cnt>=p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int low = 0,high = nums[n-1]-nums[0],ans = 0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(mid,nums,p)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};