class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> inDeg(n);
        vector<vector<int>> adjList(n),dp(n,vector<int> (26));
        for(auto it: edges){
            int u = it[0],v = it[1];
            adjList[u].push_back(v);
            inDeg[v]++;
        }
        queue<int> q;
        for(int i = 0; i<n; i++){
            if(inDeg[i]==0) q.push(i);
        }
        int cnt = 0,maxi = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            dp[node][colors[node]-'a']++;
            maxi = max(maxi,dp[node][colors[node]-'a']);
            cnt++;
            for(auto it: adjList[node]){
                for(int i = 0; i<26; i++){
                    dp[it][i] = max(dp[it][i],dp[node][i]);
                }
                inDeg[it]--;
                if(inDeg[it]==0) q.push(it);
            }
        }
        if(cnt!=n) return -1;
        return maxi;
    }
};