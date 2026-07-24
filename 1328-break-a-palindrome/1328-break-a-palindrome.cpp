class Solution {
public:

    bool isPalindrome(string s){
        int n = s.size(),i = 0,j = n-1;
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }

    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        string ans;
        for(int i = 0; i<n; i++){
            string str = palindrome;
            char og = str[i];
            for(char ch = 'a'; ch<='z'; ch++){
                if(ch==og) continue;
                str[i] = ch;
                if(!isPalindrome(str)){
                    if(ans.empty()) ans = str;
                    else if(str<ans) ans = str;
                }
                str[i] = og;
            }
        }
        return ans;
    }
};