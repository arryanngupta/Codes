class Solution {
public:

    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        if(n>m) return false;
        int i = 0,j = 0;
        while(i<n && j<m){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else j++;
        }
        if(i==n) return true;
        i = 0,j = 0;
        int cnt = 0;
        while(i<n && j<m){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                j++;
                if(i<n && s[i+1]==t[j]){
                    i++;
                    cnt++;
                }
            }
        }
        if(cnt==1 && i==n) return true;
        return false;
    }
};