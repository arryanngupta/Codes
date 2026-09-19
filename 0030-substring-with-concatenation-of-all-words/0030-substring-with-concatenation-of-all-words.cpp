class Solution {
public:

    unordered_map<string,int> mpp;

    bool find(int st,int en,string &s,int 
    &len,int &l1){
        int n = s.size(),cnt1 = 0;
        int i = st,j = st;
        string curr = "";
        unordered_map<string,int> mpp2;
        while(j<=en){
            curr += s[j];
            if(curr.size()==len){
                mpp2[curr]++;  
                curr = "";
            }
            j++;
        }
        return mpp2==mpp;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int l1 = words.size();
        int l2 = words[0].size();
        int i = 0,j = 0;
        string curr = "";
        for(auto it: words){
            mpp[it]++;
        }
        int total = l1*l2;
        vector<int> ans;
        while(j<n){
            if((j-i+1)==total){
                if(find(i,j,s,l2,l1)){
                    ans.push_back(i);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};