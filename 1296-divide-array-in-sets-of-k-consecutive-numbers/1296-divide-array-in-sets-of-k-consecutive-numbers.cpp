class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k!=0) return false;
        unordered_map<int,int> mpp;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it: nums){
            mpp[it]++;
            pq.push(it);
        }
        while(!pq.empty()){
            int no = pq.top(),cnt = 0;
            while(cnt<k && mpp.count(no)){
                mpp[no]--;
                if(mpp[no]==0) mpp.erase(no);
                cnt++;
                no++;
            }
            if(cnt!=k) return false;
            while(!pq.empty() && !mpp.count(pq.top())) pq.pop();
        }
        return true;
    }
};