class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int,vector<int>,greater<int>> l;
        int i = 0;
        while(i<n-1){
            int diff = heights[i+1]-heights[i];
            if(diff<=0){
                i++;
                continue;
            }
            if(ladders){
                l.push(diff);
                ladders--;
            }
            else{
                if(!l.empty() && bricks>=l.top() && diff>=l.top()){
                    bricks-=l.top();
                    l.pop();
                    l.push(diff);
                }
                else if(bricks>=diff){
                    bricks-=diff;
                }
                else break;
            }
            i++;
        }
        return i;
    }
};