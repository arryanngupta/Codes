class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int i = 0,ans = 0;
        long long cap = capacity;
        while(i<n){
            cap -= plants[i];
            ans++;
            if(i+1<n && cap>=plants[i+1]){
                i++;
                continue;
            }
            else if(i+1<n){
                ans += 2*(i+1);
                cap = capacity;
            }
            i++;
        }
        return ans;
    }
};

