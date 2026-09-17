class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size(),n = mat[0].size();
        priority_queue<pair<int,vector<int>>,
        vector<pair<int,vector<int>>>,
        greater<pair<int,vector<int>>>> pq;
        int sum = 0;
        for(int i = 0; i<m; i++){
            sum += mat[i][0];
        }
        vector<int> v(m,0);
        pq.push({sum,v});
        map<vector<int>,int> mpp;
        mpp[v] = 1;
        while(k){
            sum = pq.top().first;
            v = pq.top().second;
            pq.pop();
            k--;
            if(k==0) break;
            int temp = sum;
            for(int i = 0; i<m; i++){
                int idx = v[i];
                if(idx+1<n){
                    temp -= mat[i][idx];
                    temp += mat[i][idx+1];
                    v[i]++;
                    if(!mpp.count(v)) pq.push({temp,v});
                    mpp[v] = 1;
                    v[i]--;
                    temp = sum;
                }
            }
        }
        return sum;
    }
};