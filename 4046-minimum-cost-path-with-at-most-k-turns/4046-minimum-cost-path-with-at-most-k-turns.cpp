class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<vector<vector<int>>>> dist(m,vector<vector<vector<int>>> (n,vector<vector<int>> (k+1,vector<int> (5,1e9))));
        dist[0][0][0][0] = grid[0][0];
        priority_queue<pair<pair<int,pair<int,int>>,pair<int,int>>,
        vector<pair<pair<int,pair<int,int>>,pair<int,int>>>,
        greater<pair<pair<int,pair<int,int>>,pair<int,int>>>> pq;
        pq.push({{grid[0][0],{0,0}},{0,0}});
        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int distance = pq.top().first.first;
            int turns = pq.top().first.second.first;
            int dir = pq.top().first.second.second;
            pq.pop();
            if(distance>dist[row][col][turns][dir]) continue;
            for(int i = -1; i<=1; i++){
                for(int j = -1; j<=1; j++){
                    if((i==0 && j==0) || (i!=0 && j!=0)) continue;
                    int nr = i+row,nc = j+col;
                    if(nr>=0 && nr<m && nc>=0 && nc<n){
                        int updDir = 0,updTurn = turns;
                            if(j==1) updDir = 2;
                            else if(j==-1) updDir = 4;
                            else if(i==1) updDir = 3;
                            else updDir = 1;
                            if(dir!=0 && updDir!=dir) updTurn++;
                        if(updTurn<=k && distance+grid[nr][nc]<dist[nr][nc][updTurn][updDir]){
                            dist[nr][nc][updTurn][updDir]=distance+grid[nr][nc];
                            pq.push({{distance+grid[nr][nc],{updTurn,updDir}},{nr,nc}});
                        }
                    }
                }
            }
        }
        int mini = 1e9;
        for(int i = 0; i<=k; i++){
            for(int dir = 0; dir<5; dir++){
                mini = min(mini,dist[m-1][n-1][i][dir]);
            }
        }
        return mini==1e9?-1:mini;
    }
};