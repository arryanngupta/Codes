class Solution {
public:

    char processStr(string s, long long k) {
        int n = s.size();
        long long len = 0;
        for(auto it: s){
            if(it>='a' && it<='z') len++;
            else if(it=='*' && len) len--;
            else if(it=='#') len *= 2;
        }
        if(k>=len) return '.';
        for(int i = n-1; i>=0; i--){
            if(s[i]=='*'){
                len++;
            }
            else if(s[i]=='%'){
                k = len-k-1;
            }
            else if(s[i]=='#'){
                if(k>=(len/2)) k = k-(len/2);
                len = len/2;
            }
            else{
                len--;
            }
            if(len==k) return s[i];
        }
        return '.';
    }
};