class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(),mini = 1e9,maxi = 0,idx = -1;
        int i = 0;
        while(i<n){
            int cnt = 0,g = 0,j = i,flag = 0;
            while(cnt<n){
                cnt++;
                g += gas[j];
                if(g>=cost[j]) g -= cost[j];
                else{
                    flag = 1;
                    break;
                }
                j = (j+1)%n;
            }
            if(flag==0) return i;
            if(i==j){
                i++;
                continue;
            }
            if(j<i) break;
            i = j;
        }
        return -1;
    }
};