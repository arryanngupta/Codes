class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int Xor = 0;
        for(auto it: nums) Xor ^= it;
        int bit = 0;
        while(Xor){
            if(Xor%2!=0) break;
            Xor /= 2;
            bit++;
        }
        int a = 0,b = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]&(1<<bit)) a^=nums[i];
            else b^= nums[i];
        }
        return {a,b};
    }
};