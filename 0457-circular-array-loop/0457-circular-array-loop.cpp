class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size(),i = 0;
        while(i<n){
            int j = (i+nums[i]%n+n)%n,cnt = 1,pos = 0;
            if(nums[i]>0) pos = 1;
            vector<int> visited(n);
            while(i!=j && !visited[j]){
                if((pos && nums[j]<0) || (!pos && nums[j]>0)) break;
                cnt++;
                visited[j] = 1;
                j = (j + nums[j] % n + n) % n;
            }
            if((i==j) && (cnt>1)) return true;
            i++;
        }
        return false;
    }
};