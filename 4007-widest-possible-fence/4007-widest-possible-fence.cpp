class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<long long,int> mpp,mpp2;
        vector<int> a;
        for(auto it: planks){
            mpp[it]++;
        }
        for(auto it: mpp) a.push_back(it.first);
        int n = a.size();
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                long long sum = a[i]+a[j];
                if(i==j) mpp2[sum] += mpp[a[i]]/2;
                else mpp2[sum] += min(mpp[a[i]],mpp[a[j]]);
            }
        }
        int maxi = 0;
        for(auto it: mpp2){
            int val = it.second + mpp[it.first];
            maxi = max(maxi,val);
        }
        for(auto it: mpp) maxi = max(maxi,it.second);
        return maxi;
    }
};