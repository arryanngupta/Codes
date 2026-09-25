class Solution {
public:

    vector<int> maximumMEX(vector<int>& nums) {
        int i = 0,n = nums.size();
        int cnt = 0;
        unordered_map<int,int> mpp;
        vector<int> result,suffMex(n);
        int val = 0;
        for(int i = n-1; i>=0; i--){
            mpp[nums[i]]++;
            while(mpp.count(val)) val++;
            suffMex[i] = val;
        }
        int mex = suffMex[0];
        int maxi = *max_element(nums.begin(),nums.end());
        vector<pair<int,int>> a(maxi+1,{0,0});
        int t = 0;
        while(i<n){
            if(nums[i]<mex && (a[nums[i]].first==0 || a[nums[i]].second<t)) cnt++;
            if(a[nums[i]].second==t) a[nums[i]].first++;
            else{
                a[nums[i]] = {1,t};
            }
            int val = cnt==mex?mex:-1;
            if(val!=-1){
                result.push_back(val);
                t++;
                if(i+1<n) mex = suffMex[i+1];
                cnt = 0;
            }
            i++;
        }
        return result;
    }
};