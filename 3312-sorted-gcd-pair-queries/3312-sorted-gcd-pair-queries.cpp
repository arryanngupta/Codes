class Solution {
public:

    vector<long long> a;

    void getDivisors(int n){
        for(int i = 1; 1LL*i*i<=n; i++){
            if(n%i==0){
                a[i]++;
                if(n/i!=i){
                    a[n/i]++;
                }
            }
        }
    }

    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int len = *max_element(nums.begin(),nums.end());
        a.assign(len+1,0);
        for(auto it: nums){
            getDivisors(it);
        }
        for(int i = len; i>0; i--){
            if(a[i]==0) continue;
            long long freq = a[i],pairs = freq*(freq-1)/2;
            for(int j = 2*i; j <= len; j += i){
                pairs -= a[j];
            }
            a[i] = pairs;
        }
        for(int i = 1; i <= len; i++){
            a[i] += a[i - 1];
        }        
        vector<int> ans;
        for(auto it: queries){
            int low = 0,high = len;
            // int res = 0;
            // while(low<=high){
            //     int mid = low+(high-low)/2;
            //     if(a[mid]>it){
            //         res = mid;
            //         high = mid-1;
            //     }
            //     else{
            //         low = mid+1;
            //     }
            // }
            int res = lower_bound(a.begin(),a.end(),it+1)-a.begin();
            ans.push_back(res);
        }
        return ans;
    }
};