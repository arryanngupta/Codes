class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> a(m,vector<int> (n));
        int k1 = k%n;
        int nr = 0,nc = 0;
        for(int j = n-k1; j<n; j++){
            for(int i = 0; i<m; i++){
                a[i][nc] = grid[i][j];
            }
            nc++;
        }
        for(int j = 0; j<n-k1; j++){
            for(int i = 0; i<m; i++){
                a[i][nc] = grid[i][j];
            }
            nc++;
        }
        int j = 0;
        while(k--){
            int prev = a[0][j];
            for(int i = 1; i<m; i++){
                int curr = a[i][j];
                a[i][j] = prev;
                prev = curr;
            }
            a[0][j] = prev;
            j = (j+1)%n;
        }
        return a;
    }
};