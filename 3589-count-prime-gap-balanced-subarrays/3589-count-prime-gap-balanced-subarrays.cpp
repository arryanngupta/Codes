class Solution {
public:
    int primeSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int> primes(maxi+1,1);
        primes[0] = 0;
        primes[1] = 0;
        for(int i = 2; i*i<=maxi; i++){
            if(primes[i]){
                for(int j = i*i; j<=maxi; j+=i){
                    primes[j] = 0;
                }
            }
        }
        vector<int> a(n,-1);
        int cnt = 0,f = -1,s = -1;
        for(int i = 0; i<n; i++){
            if(primes[nums[i]]){
                cnt++;
                if(f==-1) f = i;
                else if(s == -1) s = i;
                else{
                    f = s;
                    s = i;
                }
            }
            if(cnt>1) a[i] = f;
        }
        priority_queue<pair<int,int>> mx_pq;
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> mn_pq;
        int i = 0,j = 0,ans = 0;
        unordered_map<int,int> mpp;
        int primeCnt = 0;
        while(j<n){
            mpp[j]=1;
            if(primes[nums[j]]){
                mn_pq.push({nums[j],j});
                mx_pq.push({nums[j],j});
                primeCnt++;
            }
            while(!mn_pq.empty() && !mpp.count(mn_pq.top().second)) mn_pq.pop();
            while(!mx_pq.empty() && !mpp.count(mx_pq.top().second)) mx_pq.pop();
            if(!mn_pq.empty() && !mx_pq.empty() && mx_pq.top().first-mn_pq.top().first>k){
                mpp.erase(i);
                if(primes[nums[i]]) primeCnt--;
                i++;
                continue;
            }
            if(primeCnt>=2){
                int idx = a[j];
                if(idx>=i) ans+=idx-i+1;
            }
            j++;
        }
        return ans;
    }
};