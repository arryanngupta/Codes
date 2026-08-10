class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size(),m = discounts.size();
        sort(prices.begin(),prices.end(),greater<int> ());
        sort(discounts.begin(),discounts.end(),greater<int> ());
        double sum = 0;
        for(int i = 0; i<min(n,m); i++){
            double val = (prices[i]*(100-discounts[i]))/(double)100;
            sum += val;
        }
        int i = min(n,m);
        while(i<n){
            sum += prices[i++];
        }
        return sum;
    }
};