class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int cnt = 0,n = nums.size(),totalEven = 0,totalOdd = 0,e = 0,o = 0;
        for(int i = 0; i<n; i++){
            if(i%2==0) totalEven += nums[i];
            else totalOdd += nums[i];
        }
        for(int i = 0; i<n; i++){
            if(i%2==0){
                totalEven -= nums[i];
            }
            else{
                totalOdd -= nums[i];
            }
            if(e+totalOdd==o+totalEven) cnt++;
            if(i%2==0) e+=nums[i];
            else o+=nums[i];
        }
        return cnt;
    }
};