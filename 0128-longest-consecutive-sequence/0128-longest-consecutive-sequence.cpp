class Solution {
public:
    int longestConsecutive(vector<int>& a) {
         int n = a.size();
         if(n == 0){
            return 0;
         }
    unordered_set<int> st;
    for(auto it: a){
        st.insert(it);
    }
    int cnt = 1,maxCnt = 1,x = 1;
    for(auto it: st){
        x = 1;
        cnt = 1;
        if(st.find(it-1) == st.end()){
            while(st.find(it+x) != st.end()){
                cnt++;
                maxCnt = max(cnt,maxCnt);
                x++;
            }
        }
    }
    return maxCnt;
    }
};