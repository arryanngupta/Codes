class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int nxtPow = log2(n)+1;
        int extra = (1<<nxtPow)-n-1;
        return (n+1+extra);
    }
};