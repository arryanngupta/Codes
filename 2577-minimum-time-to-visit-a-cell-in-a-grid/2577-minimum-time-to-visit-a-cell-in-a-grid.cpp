class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> dist(m,vector<int> (n,1e9));
        dist[0][0] = 0;
        while(!pq.empty()){
            int distance = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            for(int i = -1; i<=1; i++){
                for(int j = -1; j<=1; j++){
                    if((i==0 && j==0)||(i!=0 && j!=0)) continue;
                    int nr = i+row,nc = j+col;
                    if(nr>=0 && nr<m && nc>=0 && nc<n){
                        int newDist = distance+1;
                        if(grid[nr][nc]<=newDist){
                            if(newDist<dist[nr][nc]){
                                dist[nr][nc] = newDist;
                                pq.push({dist[nr][nc],{nr,nc}});
                            }
                        }
                        else{
                            int right = grid[0][1]<=1?1:0;
                            int down = (grid[1][0]<=1)?1:0;
                            if(!right && !down) continue;
                            int diff = grid[nr][nc]-newDist;
                            int total = grid[nr][nc]+(diff%2);
                            if(total<dist[nr][nc]){
                                dist[nr][nc] = total;
                                pq.push({dist[nr][nc],{nr,nc}});
                            }
                        }
                    }
                }
            }
        }
        if(dist[m-1][n-1]==1e9) return -1;
        return dist[m-1][n-1];
    }
};