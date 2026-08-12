class Solution {
public:

    vector<string> ans;

    void recFind(int idx,string curr,string &num,long long target, int n,
                 long long value, long long prev){
        if(idx==n){
            if(value==target) ans.push_back(curr);
            return ;
        }
        long long val = 0;
        for(int i = idx; i<n; i++){
            if(i > idx && num[idx] == '0') break;
            val = val*10+(num[i]-'0');
            string s = num.substr(idx,i-idx+1);
            if(idx == 0) {
                recFind(i + 1, s, num, target, n,val, val);
            }
            else {
                recFind(i + 1,curr + "+" + s,num, target, n,value + val,val);

                recFind(i + 1,curr + "-" + s,num, target, n,value - val,-val);

                recFind(i + 1,curr + "*" + s,num, target, n,value - prev + prev * val,prev * val);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        int n = num.size();
        ans.clear();
        recFind(0,"",num,target,n,0,0);
        return ans;
    }
};