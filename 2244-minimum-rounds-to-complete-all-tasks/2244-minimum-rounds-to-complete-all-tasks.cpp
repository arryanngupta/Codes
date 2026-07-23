class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mpp;
        for(auto it: tasks){
            mpp[it]++;
        }
        int ans = 0;
        for(auto it: mpp){
            int freq = it.second;
            if(freq<2) return -1;
            if(freq%3==0){
                ans += freq/3;
            }
            else if((freq%3)%2==0){
                ans += freq/3;
                int rem = freq%3;
                ans += rem/2;
            }
            else{
                ans+=2;
                ans += (freq-4)/3;
            }
        }
        return ans;
    }
};