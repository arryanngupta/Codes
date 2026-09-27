class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size(),maxi = min(2,n);
        for(int i = 0; i<n; i++){
            int freq[501] = {0};
            int flag = 0;
            for(int j = i; j<n; j++){
                for(int num = 1; num<501; num++){
                    if(freq[num]==0) continue;
                    int sum = nums[j]+num,diff = nums[j]-num;
                    if(sum<501 && freq[sum]){
                        flag = 1;
                        break;
                    }
                    if(diff>=0 && (diff!=num && freq[diff]) || (diff==num && freq[diff]>1)){
                        flag = 1;
                        break;
                    }
                }
                if(flag) break;
                else maxi = max(maxi,j-i+1);
                freq[nums[j]]++;
            }
        }
        return maxi;
    }
};