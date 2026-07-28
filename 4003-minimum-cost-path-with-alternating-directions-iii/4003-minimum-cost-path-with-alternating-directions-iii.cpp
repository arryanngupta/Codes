class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        priority_queue< pair<long long,pair<pair<int,int>,int>>,
        vector<pair<long long,pair<pair<int,int>,int>>>,
        greater<pair<long long,pair<pair<int,int>,int>>> > pq;
        pq.push({1,{{0,0},1}});
        vector<vector<vector<long long>>> dist(m,vector<vector<long long>> (n,vector<long long> (2,1e18)));
        dist[0][0][1] = 1;
        while(!pq.empty()){
            long long distance = pq.top().first;
            int row = pq.top().second.first.first,col = pq.top().second.first.second;
            int p = pq.top().second.second;
            pq.pop();
            long long wtDist = distance+penalty[row][col];
            if(wtDist<dist[row][col][1-p]){
                dist[row][col][1-p] =wtDist;
                pq.push({dist[row][col][1-p],{{row,col},1-p}});
            }
            if(p){
                if(row+1<m){
                    long long newDist = distance+(row+2)*(col+1);
                    if(newDist<dist[row+1][col][0]){
                        dist[row+1][col][0] = newDist;
                        pq.push({newDist,{{row+1,col},0}});
                    }
                }
                if(col+1<n){
                    long long newDist = distance+(row+1)*(col+2);
                    if(newDist<dist[row][col+1][0]){
                        dist[row][col+1][0] = newDist;
                        pq.push({newDist,{{row,col+1},0}});
                    }
                }
                if(row-1>=0){
                    long long newDist = distance+(row)*(col+1)+penalty[row][col];
                    if(newDist<dist[row-1][col][0]){
                        dist[row-1][col][0] = newDist;
                        pq.push({newDist,{{row-1,col},0}});
                    }
                }
                if(col-1>=0){
                    long long newDist = distance+(row+1)*(col)+penalty[row][col];
                    if(newDist<dist[row][col-1][0]){
                        dist[row][col-1][0] = newDist;
                        pq.push({newDist,{{row,col-1},0}});
                    }
                }
            }
            else{
                if(row+1<m){
                    long long newDist = distance+(row+2)*(col+1)+penalty[row][col];
                    if(newDist<dist[row+1][col][1]){
                        dist[row+1][col][1] = newDist;
                        pq.push({newDist,{{row+1,col},1}});
                    }
                }
                if(col+1<n){
                    long long newDist = distance+(row+1)*(col+2)+penalty[row][col];
                    if(newDist<dist[row][col+1][1]){
                        dist[row][col+1][1] = newDist;
                        pq.push({newDist,{{row,col+1},1}});
                    }
                }
                if(row-1>=0){
                    long long newDist = distance+(row)*(col+1);
                    if(newDist<dist[row-1][col][1]){
                        dist[row-1][col][1] = newDist;
                        pq.push({newDist,{{row-1,col},1}});
                    }
                }
                if(col-1>=0){
                    long long newDist = distance+(row+1)*(col);
                    if(newDist<dist[row][col-1][1]){
                        dist[row][col-1][1] = newDist;
                        pq.push({newDist,{{row,col-1},1}});
                    }
                }
            }
        }
        return min(dist[m-1][n-1][0],dist[m-1][n-1][1]);
    }
};