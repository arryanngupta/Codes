class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long maxi = 0,n = nums.size();
        vector<long long> prefixGcd(n);
        for(int i = 0; i<n; i++){
            maxi = max(maxi,1LL*nums[i]);
            prefixGcd[i] = __gcd(1LL*nums[i],maxi);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long ans = 0;
        int i = 0,j = n-1;
        while(i<j){
            ans += __gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }
        return ans;
    }
};