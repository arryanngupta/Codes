class Solution {
public:

    bool check(int mid,vector<int>& weights, int days){
        int n = weights.size(),res = 0,sum=0;
        for(int i = 0; i<n; i++){
            if(weights[i]>mid) return 0;
            if(sum+weights[i]>mid){
                sum = weights[i];
                res++;
            }
            else{
                sum += weights[i];
            }
        }
        if(sum) res++;
        return res<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *min_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = 0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(mid,weights,days)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};