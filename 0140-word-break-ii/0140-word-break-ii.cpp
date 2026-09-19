class Solution {
public:

    unordered_map<string,int> mpp;
    vector<string> ans;

    void recFind(int idx,string curr,string s, vector<string>& wordDict){
        if(idx>=s.size()){
            if(curr.size()) ans.push_back(curr);
            return;
        }
        for(int i = idx; i<s.size(); i++){
            string str = s.substr(idx,i-idx+1);
            if(mpp.count(str)){
                string updCurr = curr;
                if(curr.size()) updCurr+=" "+str;
                else updCurr += str;
                recFind(i+1,updCurr,s,wordDict);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        for(auto it: wordDict){
            mpp[it] = 1;
        }
        recFind(0,"",s,wordDict);
        return ans;
    }
};