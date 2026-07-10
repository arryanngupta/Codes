class Solution {
public:

    int check(int mid,vector<int> &a,int k){
        int n = a.size();
        int i = 0,res = 0;
        while(i<n){
            if(a[i]<=mid){
                res++;
                i+=2;
            }
            else i++;
        }
        return res>=k;
    }

    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());
        int ans = 0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(mid,nums,k)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};