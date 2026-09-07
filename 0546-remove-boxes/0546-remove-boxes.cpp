class Solution {
public:

    unordered_map<int,int> mpp;
    vector<int> a,b;
    vector<vector<vector<int>>> dp;

    int recFind(int i,int j,int num,vector<int>& boxes,int n){
        if(i>j) return 0;
        if(dp[i][j][num]!=-1) return dp[i][j][num];
        int cons = a[i]+num;
        int ans = 0;
        ans = cons*cons+recFind(i+a[i],j,0,boxes,n);
        int p = i+a[i];
        while(p<=j){
            if(boxes[p]==boxes[i]){
                ans = max(ans,recFind(i+a[i],p-1,0,boxes,n)+recFind(p,j,cons,boxes,n));
                p += a[p];
            }
            else p++;
        }
        return dp[i][j][num]=ans;
    }

    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        dp.resize(n,vector<vector<int>> (n,vector<int> (n+1,-1)));
        a.resize(n);
        int i = 0;
        while(i<n){
            if(i+1==n || boxes[i]!=boxes[i+1]){
                a[i] = 1;
                i++;
                continue;
            }
            int cnt = 1,j = i;
            while(j+1<n && boxes[j]==boxes[j+1]){
                j++;
                cnt++;
            }
            a[i] = cnt;
            i = j+1;
        }
        b.resize(n,-1);
        i = n-1;
        while(i>=0){
            while(i>0 && boxes[i-1]==boxes[i]) i--;
            if(!mpp.count(boxes[i])) b[i] = -1;
            else{
                b[i] = mpp[boxes[i]];
            }
            mpp[boxes[i]]=i;
            i--;
        }
        return recFind(0,n-1,0,boxes,n);
    }
};
