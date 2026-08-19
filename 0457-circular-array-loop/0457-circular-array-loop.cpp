class Solution {
public:

    int find(int idx,vector<int>& nums,int pos){
        int n = nums.size();
        int nxtIdx = (idx+nums[idx]%n+n)%n;
        if(idx==nxtIdx || (pos && nums[nxtIdx]<0) || (!pos && nums[nxtIdx]>0)) return -1;
        return nxtIdx;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size(),i = 0;
        vector<int> visited(n);
        while(i<n){
            if(visited[i]){
                i++;
                continue;
            }
            visited[i] = 1;
            int slow = i,fast = i,pos = nums[i]>0;
            while(true){
                slow = find(slow,nums,pos);
                fast = find(fast,nums,pos);
                if(slow==-1||fast==-1) break;
                visited[slow] = 1;
                visited[fast] = 1;
                fast = find(fast,nums,pos);
                if(fast==-1) break;
                visited[fast] = 1;
                if(fast==slow) return true;
            }
            i++;
        }
        return false;
    }
};