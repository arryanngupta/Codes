class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i = 0,j = 0;
        string ans = "";
        int o = 0,z = 0;
        while(j<n){
            if(s[j]=='1') o++;
            else z++;
            while(o>=k){
                if(s[i]=='1') o--;
                else z--;
                if(o==k-1){
                    if(ans.empty()) ans = s.substr(i,j-i+1);
                    else if(j-i+1<ans.size()) ans = s.substr(i,j-i+1);
                    else if(j-i+1==ans.size()){
                        string str = s.substr(i,j-i+1);
                        if(str<ans) ans = str;
                    }
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};