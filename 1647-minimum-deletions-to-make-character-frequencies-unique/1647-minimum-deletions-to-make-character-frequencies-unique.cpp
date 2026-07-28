class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        unordered_map<char,int> mpp,mpp2;
        for(auto it: s){
            mpp[it]++;
        }
        for(auto it: mpp){
            mpp2[it.second]++;
        }
        vector<pair<int,char>> a;
        for(auto it: mpp){
            a.push_back({it.second,it.first});
        }
        sort(a.begin(),a.end(),greater<pair<int,char>> ());
        int ans = 0,cnt = INT_MAX;
        for(auto it: a){
            char ch = it.second;
            if(!mpp.count(ch)) continue;
            int freq = it.first;
            if(mpp2[freq]>1){
                if(cnt<freq){
                    ans += freq-cnt;
                }
                cnt = min(cnt,freq);
                while(mpp2.count(cnt)){
                    ans++;
                    cnt--;
                }
                if(cnt>0) mpp2[cnt] = 1;
                mpp2[freq]--;
            }
        }
        return ans;
    }
};