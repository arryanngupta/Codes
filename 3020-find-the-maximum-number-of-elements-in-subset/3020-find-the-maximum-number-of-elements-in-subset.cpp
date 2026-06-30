class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size(),ans = 0,maxi = 1,one = 0;
        unordered_map<long long,int> mpp,vis;
        for(auto it: nums) mpp[it]++;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<n; i++){
            if(nums[i]==1||(mpp[nums[i]]<2) || vis.count(nums[i])){
                if(nums[i]==1) one++;
                continue;
            }
            long long val = nums[i];
            int pow = 1,ans = 0;
            while(mpp.count(val)){
                vis[val] = 1;
                if(mpp[val]==1){
                    ans++;
                    break;
                }
                ans += 2;
                val *= val;
            }
            if(!mpp.count(val)) ans--;
            maxi = max(maxi,ans);
        }
        if(one%2==0) one--;
        return max(one,maxi);
    }
};