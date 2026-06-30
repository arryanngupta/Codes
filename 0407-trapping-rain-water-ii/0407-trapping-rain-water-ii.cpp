class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(),n = heightMap[0].size();
        priority_queue< pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>> > pq;
        vector<vector<int>> vis(m,vector<int> (n,0));
        for(int i = 0; i<m; i++){
            pq.push({heightMap[i][0],{i,0}});
            pq.push({heightMap[i][n-1],{i,n-1}});
            vis[i][0] = vis[i][n-1] = 1;
        }
        for(int j = 0; j<n; j++){
            pq.push({heightMap[0][j],{0,j}});
            pq.push({heightMap[m-1][j],{m-1,j}});
            vis[0][j] = vis[m-1][j] = 1;
        }
        int ans = 0;
        while(!pq.empty()){
            int h = pq.top().first;
            int x = pq.top().second.first,y = pq.top().second.second;
            pq.pop();
            for(int i = -1; i<=1; i++){
                for(int j = -1; j<=1; j++){
                    if((i==0 && j==0)||(i!=0 && j!=0)) continue;
                    int nx = x+i,ny = y+j;
                    if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny]){
                        vis[nx][ny] = 1;
                        ans += max(0,h-heightMap[nx][ny]);
                        pq.push({max(h,heightMap[nx][ny]),{nx,ny}});
                    }
                }
            }
        }
        return ans;
    }
};