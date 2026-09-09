class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m = matrix[0].size();
        vector<vector<long long>> prefixSum(n,vector<long long> (m));
        for(int i = 0; i<n; i++){
            long long sum = 0;
            for(int j = 0; j<m; j++){
                sum += matrix[i][j];
                prefixSum[i][j] = sum;
            }
        }
        int ans = 0;
        for(int j = 0; j<m; j++){
            for(int j1 = j; j1<m; j1++){
                unordered_map<long long,int> mpp;
                mpp[0] = 1;
                long long sum = 0;
                for(int i = 0; i<n; i++){
                    sum += prefixSum[i][j1];
                    if(j!=0) sum -= prefixSum[i][j-1];
                    if(mpp.count(sum-target)) ans += mpp[sum-target];
                    mpp[sum]++;
                }
            }
        }
        return ans;
    }
};