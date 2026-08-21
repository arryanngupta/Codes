class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i = 0,j = n-1,ans = 0,rMaxi = 0,lMaxi = 0;
        while(i<=j){
            lMaxi = max(lMaxi,height[i]);
            rMaxi = max(rMaxi,height[j]);
            if(height[i]<=height[j]){
                ans += min(lMaxi,rMaxi)-height[i];
                i++;
            }
            else{
                ans += min(lMaxi,rMaxi)-height[j];
                j--;
            }
        }
        return ans;
    }
};