class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int,int>> a(n);
        for(int i = 0; i<n; i++){
            a[i] = {growTime[i],plantTime[i]};
        }
        sort(a.begin(),a.end(),greater<pair<int,int>> ());
        int maxi = 0,block = 0;
        for(int i = 0; i<n; i++){
            int pt = a[i].second,gt = a[i].first;
            block += pt;
            maxi = max(maxi,block+gt);
        }
        return maxi;
    }
};