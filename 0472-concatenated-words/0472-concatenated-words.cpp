class Solution {
public:
    unordered_map<string,int> mpp;
    unordered_map<string,int> dp;

    int recFind(string s){
        if(s.size()==0){
            return 0;
        }
        if(dp.count(s)) return dp[s];
        int ans = -1e9;
        string str="";
        for(int i = 0; i<s.size(); i++){
            str += s[i];
            if(mpp.count(str)){
                string updS = s.substr(i+1);
                ans = max(ans,1+recFind(updS));
            }
        }
        return dp[s]=ans;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto it: words){
            mpp[it] = 1;
        }
        int n = words.size();
        vector<string> ans;
        int len = words[0].size();
        for(auto it: words){
            if(recFind(it)>=2) ans.push_back(it);
        }
        return ans;
    }
};