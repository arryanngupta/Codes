class Solution {
public:

    long long mod = (1e9+7);

    int check(long long mid,vector<int>& value, vector<int>& decay, long long m){
        int n = value.size();
        long long res = 0;
        for(int i = 0; i<n; i++){
            if((int)mid>value[i]) continue;
            res += ((value[i]-mid)/decay[i])+1;
        }
        return res>=m;
    }
        
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        int n = value.size();
        long long low = 0,high = *max_element(value.begin(),value.end()),val = 0,ans = 0;
        while(low<=high){
            long long mid = low+(high-low)/2;
            if(check(mid,value,decay,m)){
                val = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        long long taken = 0;
        for(int i = 0; i<n; i++){
            if((int)val>value[i]) continue;
            long long no = ceil((value[i]-val)/(double)decay[i]);
            taken += no;
            long long first = value[i]-decay[i]*(no-1);
            long long temp = (first+value[i]);
            if(no%2==0) no = no/2;
            else temp /= 2;
            long long sum = ((no%mod)*(temp%mod))%mod;
            ans = (ans+sum)%mod;
        }
        if(m>taken) ans = (ans+1LL*val*(m-taken))%mod;
        return ans;
    }   
};