class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int,int>> mx_pq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mn_pq;
        unordered_map<int,int> mpp;
        int i = 0,j = 0;
        long long ans = 0;
        while(j<n){
            if(!mpp.count(j)){
                mpp[j]=1;
                mx_pq.push({nums[j],j});
                mn_pq.push({nums[j],j});
            }
            while(!mn_pq.empty() && mn_pq.top().second<i){
                mn_pq.pop();
            }
            while(!mx_pq.empty() && mx_pq.top().second<i){
                mx_pq.pop();
            }
            if(mx_pq.top().first-mn_pq.top().first>2){
                i++;
                continue;
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
};