class Solution {
public:

    vector<vector<int>> visited;
    int er,ec,ob;

    int dfs(int row,int col,int no,vector<vector<int>>& grid,int m,int n){
        if(row==er && col==ec) return (no==((m*n)-ob));
        visited[row][col] = 1;
        int ans = 0;
        for(int i = -1; i<=1; i++){
            for(int j = -1; j<=1; j++){
                if((i==0 && j==0) || (i!=0 && j!=0)) continue;
                int nr = i+row,nc = j+col;
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]!=-1 && !visited[nr][nc]){
                    ans += dfs(nr,nc,no+1,grid,m,n);
                }
            }
        }
        visited[row][col] = 0;
        return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        visited.resize(m,vector<int> (n,0));
        int sr = -1,sc = -1;
        er = -1,ec = -1,ob = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==1){
                    sr = i;
                    sc = j;
                }
                else if(grid[i][j]==2){
                    er = i;
                    ec = j;
                }
                else if(grid[i][j]==-1) ob++;
            }
        }
        return dfs(sr,sc,1,grid,m,n);
    }
};