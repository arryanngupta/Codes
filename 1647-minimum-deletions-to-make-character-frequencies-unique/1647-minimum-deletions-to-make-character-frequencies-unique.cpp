class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        unordered_map<char,int> mpp,mpp2;
        for(auto it: s){
            mpp[it]++;
        }
        int maxi = 0;
        for(auto it: mpp){
            mpp2[it.second]++;
            maxi = max(maxi,it.second);
        }
        int ans = 0;
        for(int i = maxi; i>0; i--){
            if(mpp2[i]>1){
                ans += mpp2[i]-1;
                mpp2[i-1] +=  mpp2[i]-1;
                mpp2[i] = 1;
            }
        }
        return ans;
    }
};