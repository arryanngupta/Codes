class Solution {
public:

    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int d = events[0][0];
        priority_queue< pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>> > pq;
        int i = 0,n = events.size(),ans = 0;
        while(i<n){
            while(i<n && events[i][0]<=d){
                pq.push({events[i][1],events[i][0]});
                i++;
            }
            while(!pq.empty() && d>pq.top().first){
                pq.pop();
            }
            if(!pq.empty()){
                ans++;
                d++;
                pq.pop();
            }
            else if(i<n) d = events[i][0];
        }    
        while(!pq.empty()){
            while(!pq.empty() && d>pq.top().first){
                pq.pop();
            }
            if(!pq.empty()){
                ans++;
                d++;
                pq.pop();
            }
        }
        return ans;
    }
};