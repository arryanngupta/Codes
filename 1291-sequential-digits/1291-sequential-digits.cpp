class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<long long> seq;
        vector<int> ans;
        for(int len = 2; len<10; len++){
            string s = "";
            for(int i = 1; i<=len; i++){
                s += (i+'0');
            }
            int flag = 0;
            while(flag==0){
                seq.push_back(stoll(s));
                for(int i = 0; i<s.size(); i++){
                    if(s[i]=='9'){
                        flag = 1;
                        break;
                    }
                    s[i]++;
                }
            }
        }
        long long l = low,h = high;
        for(auto it: seq){
            if(it>=l && it<=h) ans.push_back((int)it);
        }
        return ans;
    }
};