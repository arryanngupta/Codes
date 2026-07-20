class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> visited(26,0),last(26,0);
        int n = s.size();
        for(int i = 0; i<n; i++){
            last[s[i]-'a']=i;
        }
        string ans = "";
        for(int i = 0; i<n; i++){
            if(visited[s[i]-'a']) continue;
            while(!ans.empty() && ans.back()>s[i] && last[ans.back()-'a']>i){
                visited[ans.back()-'a']=0;
                ans.pop_back();
            }
            ans += s[i];
            visited[s[i]-'a']=1;
        }
        return ans;
    }
};