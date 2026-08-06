class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            string s = to_string(n);
            int prod = 1;
            for(auto it: s){
                prod *= (it-'0');
            }
            if(prod%t==0) break;
            n++;
        }
        return n;
    }
};