class Solution {
public:

    unordered_map<int,int> mpp;

    int find(int d){
        if(!mpp.count(d)) return d;
        return mpp[d] = find(mpp[d]);
    }

    static bool comp(const vector<int> &a,const vector<int> &b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }

    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(),events.end(),comp);
        int ans = 0;
        for(int i = 0; i<n; i++){
            int s = events[i][0],e = events[i][1];
            int d = find(s);
            if(d<=e){
                ans++;
                mpp[d] = d+1;
            }
        }
        return ans;
    }
};