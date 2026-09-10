class Solution {
public:

    unordered_map<int,int> mpp;

    int find(int n){
        if(n%2==0){
            return mpp[n+1];
        }
        else{
            return mpp[n-1];
        }
    }

    int check(int a,int b){
        if((a%2==0 && b%2==0) || (a%2!=0 && b%2!=0)) return false;
        if(a%2!=0) return (a-b)==1;
        return (b-a)==1;
    }

    int minSwapsCouples(vector<int>& row) {
        int n = row.size(),i=0,cnt = 0;
        for(int i = 0; i<n; i++) mpp[row[i]]=i;
        while(i<n-1){
            if(check(row[i],row[i+1])){
                i+=2;
            }
            else{
                int idx = find(row[i]);
                mpp[row[i+1]]=idx;
                mpp[row[idx]]=i+1;
                swap(row[i+1],row[idx]);
                i+=2;
                cnt++;
            }
        }
        return cnt;
    }
};