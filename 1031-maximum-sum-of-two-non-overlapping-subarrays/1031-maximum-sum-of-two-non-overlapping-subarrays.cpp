class Solution {
public:

    vector<int> prefixSum;

    int find(vector<int>& nums, int a, int b){
        int n = nums.size(),maxLeft = 0,maxi = 0;
        int i = a-1;
        while(i<n-b){
            int left = prefixSum[i+1]-prefixSum[i-a+1];
            maxLeft = max(maxLeft,left);
            int right = prefixSum[i+b+1]-prefixSum[i+1];
            maxi = max(maxi,maxLeft+right);
            i++;
        }
        return maxi;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        prefixSum.resize(n+1,0);
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            prefixSum[i+1] = sum;
        }
        return max(find(nums,firstLen,secondLen),find(nums,secondLen,firstLen));
    }
};