class Solution {
public:

    vector<int> start,finish,duration,pairSum,segTree;

    void buildSegTree(int i,int l,int r){
        if(l==r){
            segTree[i] = pairSum[l];
            return ;
        }
        int mid = (l+r)/2;
        buildSegTree(2*i+1,l,mid);
        buildSegTree(2*i+2,mid+1,r);
        segTree[i] = max(segTree[2*i+1],segTree[2*i+2]);
    }

    int recFind(int i,int l,int r,int left,int right){
        if(r<left || l>right) return 0;
        if(l>=left && r<=right) return segTree[i];
        int mid = (l+r)/2;
        return max(recFind(2*i+1,l,mid,left,right),recFind(2*i+2,mid+1,r,left,right));
    }

    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int i = 0,one = 0;
        while(i<n){
            if(s[i]=='0'){
                start.push_back(i);
                while(i<n && s[i]=='0') i++;
                finish.push_back(i-1);
                duration.push_back(finish.back()-start.back()+1);
                if(i<n) one++;
            }
            else one++;
            i++;
        }
        if(start.size()<2){
            vector<int> ans(queries.size(),one);
            return ans;
        }
        for(int i = 0; i<duration.size()-1; i++){
            pairSum.push_back(duration[i]+duration[i+1]);
        }
        int len = pairSum.size();
        segTree.assign(4*len,0);
        buildSegTree(0,0,len-1);
        vector<int> ans;
        for(auto it: queries){
            int l = it[0],r = it[1];
            int lb = lower_bound(finish.begin(),finish.end(),l)-finish.begin();
            int ub = upper_bound(start.begin(),start.end(),r)-start.begin()-1;
            int maxi = 0;
            if(lb<ub){
                int first = finish[lb]-max(start[lb],l)+1;
                int last = min(finish[ub],r)-start[ub]+1;
                if(ub-lb==1){
                    maxi = first+last;
                }
                else{
                    int a1 = first+duration[lb+1];
                    int a2 = duration[ub-1]+last;
                    int middle = recFind(0,0,len-1,lb+1,ub-2);
                    maxi = max(middle,max(a1,a2));
                }
            }
            ans.push_back(one+maxi);
        }
        return ans;
    }
};