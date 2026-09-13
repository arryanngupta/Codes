class Solution {
public:

    bool check(string s){
        int n = s.size(),i = 0,j = n-1;
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }

    static vector<long long> o,e;

    void find(){
        int maxi = 1e5;
        for(int i = 1; i<=maxi; i++){
            string s = to_string(i);
            if(check(s)){
                if(i%2==0) e.push_back(i);
                else o.push_back(i);
            }
            string s1 = s;
            reverse(s1.begin(),s1.end());
            string total = s+s1;
            long long num = stoll(total);
            if(num%2==0) e.push_back(num);
            else o.push_back(num);
            string s2 = s;
            int flag = 0;
            for(int j = 1; j<s1.size(); j++){
                s2 += s1[j];
                flag = 1;
            }
            if(flag==0) continue;
            num = stoll(s2);
            if(num%2==0) e.push_back(num);
            else o.push_back(num);
        }
    }

    long long minOperations(vector<int>& nums) {
        if(e.empty() && o.empty()){
              find();
        sort(e.begin(),e.end());
        sort(o.begin(),o.end());
        }
      
        long long ans = 0;
        int n = nums.size();
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
vector<long long> Solution::o;
vector<long long> Solution::e;