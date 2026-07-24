class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> a;
        unordered_map<int,int> mpp;
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                int Xor = nums[i]^nums[j];
                if(!mpp.count(Xor)) a.push_back({Xor,i});
                mpp[Xor] = 1;
            }
        }
        mpp.clear();
        for(int i = n-1; i>=0; i--){
            int idx = a.size()-1;
            while(idx>=0 && a[idx].second>=i){
                int j = a[idx].second;
                int Xor = a[idx].first;
                mpp[Xor^nums[i]]=1;
                idx--;
            }
        }
        return mpp.size();
    }
};