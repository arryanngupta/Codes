class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        for(int i = 0; i<strs.size(); i++){
            vector<int> freq(26);
            for(auto it: strs[i]){
                freq[it-'a']++;
            }
            string key = "";
            for(auto it1: freq){
                key += to_string(it1)+'#';
            }
            mpp[key].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it: mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};