class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        set<pair<int,int>> st1;
        set<pair<int,int>> st2;
        st1.insert({arr[n-1],-(n-1)});
        st2.insert({arr[n-1],n-1});
        vector<int> a(n),b(n);
        a[n-1] = b[n-1] = n-1;
        for(int i = n-2; i>=0; i--){
            auto it = st2.lower_bound({arr[i],i});
            if(it==st2.end()) b[i] = -1;
            else b[i] = it->second;
            it = st1.upper_bound({arr[i],-i});
            if(it==st1.begin()) a[i] = -1;
            else{
                it--;
                a[i] = abs(it->second);
            }
            st1.insert({arr[i],-i});
            st2.insert({arr[i],i});
        }
        vector<int> o(n),e(n);
        o[n-1] = e[n-1] = 1;
        int cnt = 1;
        for(int i = n-2; i>=0; i--){
            if(b[i]!=-1){
                int idx = b[i];
                if(e[idx]){
                    cnt++;
                    o[i] = 1;
                }
            }
            if(a[i]!=-1){
                int idx = a[i];
                if(o[idx]){
                    e[i] = 1;
                }
            }
        }
        return cnt;
    }
};