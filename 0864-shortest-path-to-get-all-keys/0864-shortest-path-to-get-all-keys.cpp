class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(),n = grid[0].size(),sr = -1,sc = -1,cnt = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == '@'){
                    sr = i;
                    sc = j;
                }
                else if(grid[i][j]>='a' && grid[i][j]<='z'){
                    cnt++;
                }
            }
        }
        vector<vector<vector<int>>> dist(m,vector<vector<int>> (n,vector<int> ((1<<cnt),1e9)));
        queue<pair<pair<int,int>,pair<int,int>>> q;
        dist[sr][sc][0] = 0;
        q.push({{0,0},{sr,sc}});
        while(!q.empty()){
            int distance = q.front().first.first;
            int mask = q.front().first.second;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            if(mask==((1<<cnt)-1)) return distance;
            for(int i = -1; i<=1; i++){
                for(int j = -1; j<=1; j++){
                    if((i==0 && j==0) || (i!=0 && j!=0)) continue;
                    int nr = i+row,nc = j+col;
                    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]!='#'){
                        if(grid[nr][nc]>='a' && grid[nr][nc]<='z'){
                            int bit = grid[nr][nc]-'a';
                            int updMask = mask|(1<<bit);
                            if(distance+1<dist[nr][nc][updMask]){
                                dist[nr][nc][updMask] = distance+1;
                                q.push({{dist[nr][nc][updMask],updMask},{nr,nc}});
                            }
                        }
                        else if(grid[nr][nc]>='A' && grid[nr][nc]<='Z'){
                            int bit = grid[nr][nc]-'A';
                            if((1<<bit)&mask && distance+1<dist[nr][nc][mask]){
                                dist[nr][nc][mask] = distance+1;
                                q.push({{dist[nr][nc][mask],mask},{nr,nc}});
                            }
                        }
                        else if(distance+1<dist[nr][nc][mask]){
                                dist[nr][nc][mask] = distance+1;
                                q.push({{dist[nr][nc][mask],mask},{nr,nc}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};