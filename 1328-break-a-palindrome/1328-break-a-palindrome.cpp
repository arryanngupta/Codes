class Solution {
public:

    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n==1) return "";
        string ans = palindrome;
        for(int i = 0; i<n/2; i++){
            if(ans[i]!='a'){
                ans[i] = 'a';
                return ans;
            }
        }
        ans[n-1] = 'b';
        return ans;
    }
};