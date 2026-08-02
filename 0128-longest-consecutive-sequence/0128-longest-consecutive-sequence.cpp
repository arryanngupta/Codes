class Solution {
public:
    int longestConsecutive(vector<int>& a) {
         int n = a.size();
         if(n == 0){
            return 0;
         }
    unordered_map<int,int> mpp;
    for(auto it: a){
        mpp[it] = 1;
    }
    int cnt = 1,maxCnt = 1,x = 1;
    for(auto it: mpp){
        if(it.second==0) continue;
        x = 1;
        cnt = 1;
        if(!mpp.count(it.first-1)){
            mpp[it.first] = 0;
            while(mpp.count(it.first+x)){
                mpp[it.first+x] = 0;
                cnt++;
                maxCnt = max(cnt,maxCnt);
                x++;
            }
        }
    }
    return maxCnt;
    }
};