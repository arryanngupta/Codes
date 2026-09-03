class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n);
        int i = 0,j = 0,sum = 0,cnt = 0;
        while(j<n){
            while(j<n && j-i+1<3){
                j++;
            }
            if(j<n){
                sum += diff[i];
                if(nums[i]==1){
                    if(sum%2!=0){
                        diff[i]++;
                        if(j+1<n) diff[j+1]--;
                        cnt++;
                        sum++;
                    }
                }
                else{
                    if(sum%2==0){
                        diff[i]++;
                        if(j+1<n) diff[j+1]--;
                        cnt++;
                        sum ++;
                    }
                }
            }
            i++;
            j++;
        }
        sum=0;
        for(int i = 0; i<n; i++){
            sum += diff[i];
            if(nums[i]==1){
                if(sum%2!=0){
                    return -1;
                }
            }
            else{
                if(sum%2==0){
                    return -1;
                }
            }
        }
        return cnt;
    }
};