class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26,0);
        for(auto it: s) freq[it-'a']++;
        priority_queue<pair<int,char>> pq;
        for(int i = 0; i<26; i++){
            if(freq[i]) pq.push({freq[i],i+'a'});
        }
        string ans = "";
        while(!pq.empty()){
            char ch1 = pq.top().second;
            pq.pop();
            ans += ch1;
            freq[ch1-'a']--;
            if(pq.empty()){
                if(freq[ch1-'a']==0) break;
                else{
                    pq.push({freq[ch1-'a'],ch1});
                    continue;
                }
            }
            char ch2 = pq.top().second;
            pq.pop();
            ans += ch2;
            freq[ch2-'a']--;
            if(freq[ch1-'a']) pq.push({freq[ch1-'a'],ch1});
            if(freq[ch2-'a']) pq.push({freq[ch2-'a'],ch2});
        }
        int n = s.size();
        for(int i = 0; i<n-1; i++){
            if(ans[i]==ans[i+1]) return "";
        }
        return ans;
    }
};