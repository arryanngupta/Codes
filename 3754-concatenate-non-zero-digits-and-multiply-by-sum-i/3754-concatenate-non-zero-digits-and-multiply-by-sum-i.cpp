class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string str = "";
        long long sum = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i]!='0') str += s[i];
            sum += s[i]-'0';
        }
        long long x = str.size()?stoll(str):0;
        long long ans = 1LL*x*sum;
        return ans;
    }
};