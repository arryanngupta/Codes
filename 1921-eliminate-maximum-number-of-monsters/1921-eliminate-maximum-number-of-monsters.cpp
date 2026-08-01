class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> time(n);
        for(int i = 0; i<n; i++){
            time[i] = dist[i]/(double) speed[i];
        }
        sort(time.begin(),time.end());
        int ans = 0;
        int t = 0;
        for(int i = 0; i<n; i++){
            if(time[i]-t<=0) return ans;
            ans++;
            t++;
        }
        return n;
    }
};