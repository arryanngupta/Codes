class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26);
        for(auto it: word){
            freq[it-'a']++;
        }
        vector<pair<int,int>> a;
        for(int i = 0; i<26; i++){
            a.push_back({freq[i],i});
        }
        sort(a.begin(),a.end(),greater<pair<int,int>> ());
        int cnt = 0,cost = 1,ans = 0;
        for(auto it: a){
            int freq = it.first;
            ans += 1LL*cost*freq;
            cnt++;
            if(cnt==8){
                cnt = 0;
                cost++;
            }
        }
        return ans;
    }
};