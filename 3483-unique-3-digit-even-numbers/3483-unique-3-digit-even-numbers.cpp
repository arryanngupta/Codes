class Solution {
public:

    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_map<int,int> mpp;
        for(int i = 0; i<n; i++){
            if(digits[i]==0) continue;
            for(int j = 0; j<n; j++){
                if(j==i) continue;
                for(int k = 0; k<n; k++){
                    if(k==j || k==i || digits[k]%2!=0) continue;
                    int no = digits[i]*100+digits[j]*10+digits[k];
                    mpp[no] = 1;
                }
            }
        }
        return mpp.size();
    }
};