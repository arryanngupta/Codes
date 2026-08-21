class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0,j = 0,n = nums.size();
        while(i<n && j<n){
            if(nums[i]!=val){
                i++;
                continue;
            }
            j = i+1;
            while(j<n && nums[j]==val){
                j++;
            }
            if(j==n) break;
            swap(nums[i],nums[j]);
            i++;
        }
        return i;
    }
};