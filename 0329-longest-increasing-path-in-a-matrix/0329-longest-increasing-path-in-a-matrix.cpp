class Solution {
public:

    vector<vector<int>> dp;

    int dfs(int row,int col,int m,int n,vector<vector<int>>& matrix){
        if(dp[row][col]!=-1) return dp[row][col];
        int maxi = 1;
        for(int i = -1; i<=1; i++){
            for(int j = -1; j<=1; j++){
                if((i==0 && j==0)||(i!=0 && j!=0)) continue;
                int nr = i+row,nc = j+col;
                if(nr>=0 && nr<m && nc>=0 && nc<n && matrix[nr][nc]>matrix[row][col]){
                    maxi = max(maxi,1+dfs(nr,nc,m,n,matrix));
                }
            }
        }
        return dp[row][col]=maxi;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        int ans = 0;
        dp.resize(m,vector<int> (n,-1));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                ans = max(ans,dfs(i,j,m,n,matrix));
            }
        }
        return ans;
    }
};