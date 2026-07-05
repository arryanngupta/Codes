class Solution {
public:

    int mod = (int)(1e9+7);

    vector<vector<int>> dp;
    vector<vector<vector<int>>> dp2;

    int recFind(int i,int j,vector<string>& board,int n,int m){
        if(i==0 && j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = -1e9,left = -1e9,diag = -1e9;
        if(i-1>=0 && board[i-1][j]!='X'){
            int val = board[i][j]=='S'?0:board[i][j]-'0';
            up = val + recFind(i-1,j,board,n,m);
        }
        if(j-1>=0 && board[i][j-1]!='X'){
            int val = board[i][j]=='S'?0:board[i][j]-'0';
            left = val + recFind(i,j-1,board,n,m);
        }
        if(i-1>=0 && j-1>=0 && board[i-1][j-1]!='X'){
            int val = board[i][j]=='S'?0:board[i][j]-'0';
            diag = val + recFind(i-1,j-1,board,n,m);
        }
        return dp[i][j]=max(up,max(left,diag));
    }

    int recFind2(int i,int j,int sum,vector<string>& board,int n,int m){
        if(i==0 && j==0) return (sum==0);
        if(sum<0) return 0;
        if(dp2[i][j][sum]!=-1) return dp2[i][j][sum];
        int up = 0,left = 0,diag = 0;
        if(i-1>=0 && board[i-1][j]!='X'){
            int val = board[i][j]=='S'?0:board[i][j]-'0';
            up = recFind2(i-1,j,sum-val,board,n,m);
        }
        if(j-1>=0 && board[i][j-1]!='X'){
            int val = board[i][j]=='S'?0:board[i][j]-'0';
            left = recFind2(i,j-1,sum-val,board,n,m);
        }
        if(i-1>=0 && j-1>=0 && board[i-1][j-1]!='X'){
            int val = board[i][j]=='S'?0:board[i][j]-'0';
            diag = recFind2(i-1,j-1,sum-val,board,n,m);
        }
        return dp2[i][j][sum]=(0LL+up+left+diag)%mod;
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size(),m = board[0].size();
        dp.resize(n,vector<int> (m,-1));
        int sum = recFind(n-1,m-1,board,n,m);
        if(sum<0) return {0,0};
        dp2.resize(n,vector<vector<int>> (m,vector<int> (sum+1,-1)));
        int no = recFind2(n-1,m-1,sum,board,n,m);
        return {sum,no};
    }
};