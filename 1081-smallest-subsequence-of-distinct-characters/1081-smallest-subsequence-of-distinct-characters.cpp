class Solution {
public:

    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int> visited(26,0),last(26,-1);
        for(int i = 0; i<n; i++){
            last[s[i]-'a']=i;
        }
        string str = "";
        for(int i = 0; i<n; i++){
            if(visited[s[i]-'a']) continue;
            while(!str.empty() && str.back()>s[i] && last[str.back()-'a']>i){
                visited[str.back()-'a']=0;
                str.pop_back();
            }
            str += s[i];
            visited[s[i]-'a']=1;
        }
        return str;
    }
};