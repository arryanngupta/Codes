class Solution {
public:

    unordered_map<string,int> mpp;

    bool find(int i,vector<string>& arr,string &res){
        string s = arr[i];
        int n = s.size();
        for(int i = 0; i<n; i++){
            string str = "";
            for(int j = i; j<n; j++){
                str += s[j];
                mpp[str]--;
                if(mpp[str]==0) mpp.erase(str);
            }
        }
        int k = 1,flag = 0;
        while(k<=n){
            for(int i = 0; i<=n-k; i++){
                string str = s.substr(i,k);
                if(!mpp.count(str)){
                    if(res.empty()) res = str;
                    else res = min(res,str);
                }
            }
            if(!res.empty()){
                flag = 1;
                break;
            }
            k++;
        }
        for(int i = 0; i<n; i++){
            string str = "";
            for(int j = i; j<n; j++){
                str += s[j];
                mpp[str]++;
            }
        }
        return flag;
    }

    vector<string> shortestSubstrings(vector<string>& arr) {
        for(auto it: arr){
            string s = it;
            for(int i = 0; i<s.size(); i++){
                string substr = "";
                for(int j = i; j<s.size(); j++){
                    substr += s[j];
                    mpp[substr]++;
                }
            }
        }
        int n = arr.size();
        vector<string> ans(n,"");
        for(int i = 0; i<n; i++){
            string res = "";
            if(find(i,arr,res)) ans[i] = res;
        }
        return ans;
    }
};