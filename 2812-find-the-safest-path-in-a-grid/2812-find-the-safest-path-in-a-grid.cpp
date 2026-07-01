class Solution {
public:

    vector<vector<int>> dist;

    bool check(int mid,vector<vector<int>> &dist){
        int n = dist.size();
        if(dist[0][0]<mid || dist[n-1][n-1]<mid) return false;
        vector<vector<int>> visited(n,vector<int> (n,0));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = 1;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = -1; i<=1; i++){
                for(int j = -1; j<=1; j++){
                    if((i==0 && j==0)||(i!=0 && j!=0)) continue;
                    int nr = row+i,nc = col+j;
                    if(nr>=0 && nr<n && nc>=0 && nc<n && !visited[nr][nc] && dist[nr][nc]>=mid){
                        q.push({nr,nc});
                        visited[nr][nc] = 1;
                    }
                }
            }
        }
        return visited[n-1][n-1];
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue< pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>> > pq;
        dist.resize(n,vector<int> (n,1e9));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]){
                    pq.push({0,{i,j}});
                    dist[i][j] = 0;
                }
            }
        }
        while(!pq.empty()){
            int distance = pq.top().first;
            int row = pq.top().second.first,col = pq.top().second.second;
            pq.pop();
            for(int i = -1; i<=1; i++){
                for(int j = -1; j<=1; j++){
                    if(i==0 && j==0) continue;
                    int nr = row+i,nc = col+j;
                    if(nr>=0 && nr<n && nc>=0 && nc<n && distance+1<dist[nr][nc]){
                        if(i!=0 && j!=0) dist[nr][nc] = distance+2;
                        else dist[nr][nc] = distance+1;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        int mini = min(dist[0][0],dist[n-1][n-1]);
        int low = 0,high = mini,ans = 0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(mid,dist)){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
};