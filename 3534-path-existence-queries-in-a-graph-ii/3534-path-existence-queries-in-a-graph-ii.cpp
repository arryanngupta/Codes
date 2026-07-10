class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> a(n);
        for(int i = 0; i<n; i++){
            a[i] = {nums[i],i};
        }
        sort(a.begin(),a.end());
        vector<int> pos(n);
        for(int i = 0; i<n; i++){
            pos[a[i].second] = i;
        }
        int m = log2(n)+1;
        vector<vector<int>> up(n,vector<int> (m));
        int i = 0,j = 0;
        while(j<n || i<n){
            while(j<n && a[j].first-a[i].first<=maxDiff) j++;
            up[i][0] = j-1;
            i++;
        }
        for(int j = 1; j<m; j++){
            for(int node = 0; node<n; node++){
                if(up[node][j-1]!=-1) up[node][j] = up[up[node][j-1]][j-1];
            }
        }
        vector<int> ans;
        for(auto it: queries){
            int u = pos[it[0]],v = pos[it[1]];
            if(u==v){
                ans.push_back(0);
                continue;
            }
            if(u>v) swap(u,v);
            int val = 0;
            for(int j = m-1; j>=0; j--){
                if(up[u][j]<v){
                    u = up[u][j];
                    val += (1<<j);
                }
            }
            if(up[u][0]>=v){
                val++;
                ans.push_back(val);
            }
            else ans.push_back(-1);
        }
        return ans;
    }
};