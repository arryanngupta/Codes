class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int i = 0,cnt = 0;
        while(i<k){
            int j = i,len = 0;
            vector<int> a;
            while(j<n){
                int ub = upper_bound(a.begin(),a.end(),arr[j])-a.begin();
                if(ub == a.size()) a.push_back(arr[j]);
                else a[ub] = arr[j];
                j += k;
                len++;
            }
            cnt += len-a.size();
            i++;
        }
        return cnt;
    }
};