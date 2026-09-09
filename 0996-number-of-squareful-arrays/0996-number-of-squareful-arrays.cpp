class Solution {
public:

    map<pair<int,long long>,int> mpp;
    vector<int> fact;

    bool check(int prev,int i,vector<int>& nums){
        if(prev==-1) return true;
        int a = nums[i],b = nums[prev],total = a+b;
        int k=sqrt(total);
        return (k*k == total);
        // return (sqrt(total)*sqrt(total)==total);
    }

    int recFind(int prev,long long mask,vector<int>& nums,int n){
        if(mask==((1<<n)-1)){
            return 1;
        }
        if(mpp.count({prev,mask})) return mpp[{prev,mask}];
        int ans = 0;
        for(int i = 0; i<n; i++){
            if((mask&(1<<i))==0 && check(prev,i,nums)){
                int updMask = mask|(1<<i);
                ans += recFind(i,updMask,nums,n);
            }
        }
        return mpp[{prev,mask}]=ans;
    }

    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();
        fact.resize(n+1);
        fact[0] = 1;
        for(int i = 1; i<=n; i++){
            fact[i] = fact[i-1]*i;
        }
        int total = recFind(-1,0,nums,n);
        cout<<total<<endl;
        unordered_map<int,int> mpp2;
        for(auto it: nums) mpp2[it]++;
        for(auto it: mpp2){
            total /= fact[it.second];
        }
        return total;
    }
};