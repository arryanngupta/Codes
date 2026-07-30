class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int m = rowCosts.size(),n = colCosts.size();
        int a = homePos[0],b = homePos[1],c = startPos[0],d = startPos[1];
        int ans = 0;
        while(c!=a){
            if(c<a){
                c++;
            }
            else{
                c--;
            }
            ans += rowCosts[c];
        }
        while(d!=b){
            if(d<b){
                d++;
            }
            else{
                d--;
            }
            ans += colCosts[d];
        }
        return ans;
    }
};