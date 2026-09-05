class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> a(n);
        for(int i = 0; i<n; i++) a[i] = {capital[i],profits[i]};
        sort(a.begin(),a.end());
        priority_queue<int> pq;
        int i = 0;
        while(k){
            while(i<n && a[i].first<=w){
                pq.push(a[i].second);
                i++;
            }
            if(pq.empty()) break;
            w += pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};