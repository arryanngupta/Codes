class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        int sX = start[0],sY = start[1];
        int tX = target[0],tY = target[1];
        int n = tX,m = tY;
        map<pair<int,int>,int> dist;
        sort(specialRoads.begin(),specialRoads.end());
        for(auto it: specialRoads){
            int x1 = it[0]-1,y1 = it[1]-1,x2 = it[2]-1,y2 =it[3]-1,wt = it[4];
            dist[{x1,y1}]=1e9;
            dist[{x2,y2}]=1e9;
        }
        dist[{tX-1,tY-1}] = abs(sX - tX) + abs(sY - tY);
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{sX-1,sY-1}});
        dist[{sX-1,sY-1}] = 0;
        int mini = dist[{tX-1,tY-1}];
        while(!pq.empty()){
            int distance = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            mini = min(mini,distance+abs(row-(tX-1))+abs(col-(tY-1)));
            pq.pop();
            if(distance>dist[{row,col}]) continue;
            for(auto it: specialRoads){
                int x1 = it[0]-1,y1 = it[1]-1,x2 = it[2]-1,y2 =it[3]-1,wt = it[4];
                int cost = abs(row-x1)+abs(col-y1)+wt;
                if(distance+cost<dist[{x2,y2}]){
                    dist[{x2,y2}]=distance+cost;
                    pq.push({dist[{x2,y2}],{x2,y2}});
                }
            }
        }
        return mini;
    }
};