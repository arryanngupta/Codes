class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        priority_queue<pair<int,int>> mx_pq;
        priority_queue< pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>> > mn_pq;
        unordered_map<int,int> mpp;
        int i = 0,j = 0;
        while(j<n){
            while(!mn_pq.empty() && !mpp.count(mn_pq.top().second)) mn_pq.pop();
            while(!mx_pq.empty() && !mpp.count(mx_pq.top().second)) mx_pq.pop();
            if(!mn_pq.empty() && !mx_pq.empty() && (abs(mn_pq.top().first-nums[j])>2 || abs(mx_pq.top().first-nums[j])>2)){
                mpp.erase(i);
                i++;
                continue;
            }
            ans += j-i+1;
            mpp[j]=1;
            mn_pq.push({nums[j],j});
            mx_pq.push({nums[j],j});
            j++;
        }
        return ans;
    }
};