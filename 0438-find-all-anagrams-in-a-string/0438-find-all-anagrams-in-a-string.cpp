class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq(26),freq2(26);
        for(auto it: p) freq[it-'a']++;
        int i = 0,j = 0,n = s.size();
        vector<int> ans;
        while(j<n){
            freq2[s[j]-'a']++;
            while(freq2[s[j]-'a']>freq[s[j]-'a']){
                freq2[s[i]-'a']--;
                i++;
            }
            if(j-i+1==p.size()){
                ans.push_back(i);
                freq2[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};