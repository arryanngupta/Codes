class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        for(auto it: tasks) freq[it-'A']++;
        priority_queue<pair<int,char>> pq;
        for(int i = 0; i<26; i++){
            if(freq[i]) pq.push({freq[i],i+'A'});
        }
        int ans = 0;
        while(!pq.empty()){
            int f = pq.top().first;
            char ch = pq.top().second;
            if(f==1){
                ans++;
                freq[ch-'A']--;
                pq.pop();
                continue;
            }
            ans += n+1;
            int cnt = 0;
            vector<char> temp;
            while(!pq.empty() && cnt<(n+1)){
                freq[pq.top().second-'A']--;
                if(freq[pq.top().second-'A']) temp.push_back(pq.top().second);
                cnt++;
                pq.pop();
            }
            for(auto it: temp){
                pq.push({freq[it-'A'],it});
            }
        }
        return ans;
    }
};