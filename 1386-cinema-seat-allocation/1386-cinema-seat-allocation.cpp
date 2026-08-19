class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_map<int,int>> mpp;
        for(auto it: reservedSeats){
            mpp[it[0]][it[1]]=1;
        }
        int res = mpp.size();
        int ans = (n-res)*2;
        for(auto it: mpp){
            int left = 1,middle = 1,right = 1;
            for(int i = 2; i<=5; i++){
                if(mpp[it.first].count(i)){
                    left = 0;
                    break;
                }
            }
            for(int i = 4; i<=7; i++){
                if(mpp[it.first].count(i)){
                    middle = 0;
                    break;
                }
            }
            for(int i = 6; i<=9; i++){
                if(mpp[it.first].count(i)){
                    right = 0;
                    break;
                }
            }
            if(left && middle && right) ans += 2;
            else if(left || right || middle) ans++;
        }
        return ans;
    }
};


