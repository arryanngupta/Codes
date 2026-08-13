class Solution {
public:

    vector<int> fibo;

    bool check(int mid,int k){
        int n = fibo.size(),i = n-1,cnt = 0;
        while(i>=0 && k){
            if(fibo[i]>k) i--;
            else{
                k -= fibo[i];
                cnt++;
            }
        }
        return cnt<=mid;
    }

    int findMinFibonacciNumbers(int k) {
        fibo.push_back(1);
        fibo.push_back(1);
        long long k1 = k;
        while(true){
            long long val = fibo[fibo.size()-1]+fibo[fibo.size()-2];
            if(val>k1) break;
            fibo.push_back((int)val);
        }
        int low = 1,high = fibo.size(),ans = 0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(mid,k)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};