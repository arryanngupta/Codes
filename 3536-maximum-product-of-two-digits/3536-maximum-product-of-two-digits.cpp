class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        char maxi = 0,maxi2 = 0;
        for(auto it: s){
            if(it>maxi){
                maxi2 = maxi;
                maxi = it;
            }
            else if(it>maxi2){
                maxi2 = it;
            }
        }
        return (maxi-'0')*(maxi2-'0');
    }
};