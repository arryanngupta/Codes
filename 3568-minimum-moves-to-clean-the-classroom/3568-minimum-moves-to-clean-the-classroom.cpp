class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(),n = classroom[0].size();
        int sr = -1,sc = -1,cnt = 0;
        vector<vector<int>> a(m,vector<int> (n,-1));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(classroom[i][j]=='S'){
                    sr = i;
                    sc = j;
                }
                else if(classroom[i][j]=='L'){
                    cnt++;
                    a[i][j] = cnt;
                }
            }
        }
        vector<vector<vector<vector<int>>>> dist(m,vector<vector<vector<int>>> (n,vector<vector<int>> (energy+1,vector<int> ((1<<cnt),0))));
        queue<pair<int,pair<pair<int,int>,pair<int,int>>>> q; // {mask,{{dist,energy},{row,col}}}
        dist[sr][sc][energy][0]=0;
        q.push({0,{{0,energy},{sr,sc}}});
        while(!q.empty()){
            int mask = q.front().first;
            int distance = q.front().second.first.first;
            int e = q.front().second.first.second;
            int row = q.front().second.second.first;
            int col = q.front().second.second.second;
            q.pop();
            if(distance>dist[row][col][e][mask]) continue;
            if(mask == ((1<<cnt)-1)) return distance;
            if(e==0) continue;
            for(int i = -1; i<=1; i++){
                for(int j = -1; j<=1; j++){
                    if((i==0 && j==0) || (i!=0 && j!=0)) continue;
                    int nr = i+row,nc = j+col;
                    if(nr>=0 && nr<m && nc>=0 && nc<n && classroom[nr][nc]!='X'){
                        if(classroom[nr][nc]=='L'){
                            int bit = a[nr][nc]-1;
                            int updMask = (1<<bit)|mask;
                            if(!dist[nr][nc][e-1][updMask]){
                                dist[nr][nc][e-1][updMask] = distance+1;
                                q.push({updMask,{{dist[nr][nc][e-1][updMask],e-1},{nr,nc}}});
                            }
                        }
                        else if(classroom[nr][nc]=='R'){
                            if(!dist[nr][nc][energy][mask]){
                                dist[nr][nc][energy][mask] = distance+1;
                                q.push({mask,{{dist[nr][nc][energy][mask],energy},{nr,nc}}});                   
                            }
                        }
                        else{
                            if(!dist[nr][nc][e-1][mask]){
                                dist[nr][nc][e-1][mask] = distance+1;
                                q.push({mask,{{dist[nr][nc][e-1][mask],e-1},{nr,nc}}});                        
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};