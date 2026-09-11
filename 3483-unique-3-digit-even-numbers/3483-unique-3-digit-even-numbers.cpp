class Solution {
public:

    set<vector<int>> st;

    void recFind(int cnt,int mask,vector<int> a,vector<int>& digits,int n){
        if(cnt==3){
            st.insert(a);
            return ;
        }
        for(int i = 0; i<n; i++){
            if((mask&(1<<i))==0){
                if(cnt==2 && digits[i]%2!=0) continue;
                if(cnt==0 && digits[i]==0) continue;
                int updMask = mask|(1<<i);
                a.push_back(digits[i]);
                recFind(cnt+1,updMask,a,digits,n);
                a.pop_back();
            }
        }
    }

    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> a;
        recFind(0,0,a,digits,n);
        return st.size();
    }
};