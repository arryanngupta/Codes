class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(),maxi = 0;
        int i = 0,j = n-1;
        while(i<j){
            if(height[i]<=height[j]){
                maxi = max(maxi,(j-i)*height[i]);
                i++;
            }
            else{
                maxi = max(maxi,(j-i)*height[j]);
                j--;
            }
        }
        return maxi;
    }
};