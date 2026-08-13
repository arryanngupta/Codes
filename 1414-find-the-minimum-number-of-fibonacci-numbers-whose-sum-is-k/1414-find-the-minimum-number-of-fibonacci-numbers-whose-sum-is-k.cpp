class Solution {
public:

    vector<int> fibo;

    int findMinFibonacciNumbers(int k) {
        fibo.push_back(1);
        fibo.push_back(1);
        long long k1 = k;
        while(true){
            long long val = fibo[fibo.size()-1]+fibo[fibo.size()-2];
            if(val>k1) break;
            fibo.push_back((int)val);
        }
        int i = fibo.size()-1,cnt = 0;
        while(i>=0 && k){
            if(fibo[i]>k) i--;
            else{
                k -= fibo[i];
                cnt++;
            }
        }
        return cnt;
    }
};