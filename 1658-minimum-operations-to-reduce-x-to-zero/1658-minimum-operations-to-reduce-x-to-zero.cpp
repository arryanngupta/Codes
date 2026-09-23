class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int i = 0,mini = 1e9;
        while(i<n && x-nums[i]>=0){
            x -= nums[i];
            i++;
        }
        if(x==0) mini = i;
        i--;
        int j = n-1;
        while(i<j && (j>=0 || i>=0)){
            if(j>=0 && x-nums[j]>=0){
                x -= nums[j];
                if(x==0) mini = min(mini,i+1+n-j);
                j--;
            }
            else if(i>=0){
                x += nums[i];
                i--;
            }
            else break;
        }
        return mini==1e9?-1:mini;
    }
};