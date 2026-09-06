class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size(),ans = n,v = speed[n-1];
        for(int i = n-1; i>=1; i--){
            if(position[i]-position[i-1]<=distance || speed[i-1]>v) ans--;
            else v = speed[i-1];
        }
        return ans;
    }
};