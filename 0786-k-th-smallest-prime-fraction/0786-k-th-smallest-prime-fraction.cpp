class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double,pair<int,int>>,
        vector<pair<double,pair<int,int>>>,
        greater<pair<double,pair<int,int>>>> pq;
        for(int i = 0; i<n-1; i++){
            pq.push({(double)arr[i]/arr[n-1],{i,n-1}});
        }
        while(k>1){
            int i = pq.top().second.first,j = pq.top().second.second;
            pq.pop();
            pq.push({(double)arr[i]/arr[j-1],{i,j-1}});
            k--;
        }
        return {arr[pq.top().second.first],arr[pq.top().second.second]};
    }
};