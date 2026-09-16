class Solution {
public:

    static vector<long long> o,e;

    bool check(int n){
        string s = to_string(n);
        int i = 0,j = s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }

    long long minOperations(vector<int>& nums) {
        int n = nums.size(),maxi = 1e5+1;
        if(e.empty() && o.empty()){
            for(int i = 1; i<maxi; i++){
                if(check(i)){
                    if(i%2==0) e.push_back(i);
                    else o.push_back(i);
                }
                string s = to_string(i);
                string s1 = s;
                reverse(s1.begin(),s1.end());
                string total = s+s1;
                long long t = stoll(total);
                if(t%2==0) e.push_back(t);
                else o.push_back(t);
                for(int j = 1; j<s1.size(); j++){
                    s += s1[j];
                }
                t = stoll(s);
                if(t%2==0) e.push_back(t);
                else o.push_back(t);
            }
            sort(e.begin(),e.end());
            sort(o.begin(),o.end());
            e.erase(unique(e.begin(), e.end()), e.end());
            o.erase(unique(o.begin(), o.end()), o.end());
        }
        long long ans = 0;
        for(int i = 0; i<n; i++){
            long long mini = 1e18;
            if(nums[i]%2==0){
                int ub = upper_bound(e.begin(),e.end(),nums[i])-e.begin();
                if(ub<e.size()) mini = min(mini,(e[ub]-nums[i])/2);
                if(ub-1>=0) mini = min(mini,(nums[i]-e[ub-1])/2);
            }
            else{
                int ub = upper_bound(o.begin(),o.end(),nums[i])-o.begin();
                if(ub<o.size()) mini = min(mini,(o[ub]-nums[i])/2);
                if(ub-1>=0) mini = min(mini,(nums[i]-o[ub-1])/2);
            }
            ans += mini;
        }
        return ans;
    }
};
vector<long long> Solution :: o;
vector<long long> Solution :: e;