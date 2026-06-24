class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double,pair<int,int>>,
        vector<pair<double,pair<int,int>>>,
        greater<pair<double,pair<int,int>>>> pq;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                pq.push({(double)arr[i]/arr[j],{arr[i],arr[j]}});
            }
        }
        vector<int> ans(2);
        while(k--){
            ans[0] = pq.top().second.first;
            ans[1] = pq.top().second.second;
            pq.pop();
        }
        return ans;
    }
};