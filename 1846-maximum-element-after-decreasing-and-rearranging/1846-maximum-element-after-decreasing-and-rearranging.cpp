class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int num = 1;
        sort(arr.begin(),arr.end());
        int n = arr.size();
        unordered_map<int,int> mpp;
        for(int i = 0; i<n; i++){
            if(arr[i]>=num){
                mpp[num] = 1;
                num++;
            }
        }
        return mpp.count(num)?num:num-1;
    }
};