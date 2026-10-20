class Solution {
public:

    vector<int> segTree;

    int find(int i,int l,int r,int start,int end){
        if(l>r || r<start || l>end) return 0;
        if(l>=start && r<=end) return segTree[i];
        int mid = l+(r-l)/2;
        return find(2*i+1,l,mid,start,end)+find(2*i+2,mid+1,r,start,end);
    }

    void update(int i,int l,int r,int idx){
        if(l==r){
            segTree[i]++;
            return;
        }
        int mid = l+(r-l)/2;
        if(idx<=mid) update(2*i+1,l,mid,idx);
        else update(2*i+2,mid+1,r,idx);
        segTree[i] = segTree[2*i+1]+segTree[2*i+2];
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        segTree.resize(4*n);
        vector<int> a(n);
        for(int i = 0; i<n; i++){
            a[nums2[i]] = i;
        }
        long long ans = 0;
        for(int i = 0; i<n; i++){
            int y = nums1[i];
            int idx = a[y];
            long long leftCommon = find(0,0,n-1,0,idx-1);
            long long leftUnCommon = max(i,idx)-leftCommon;
            long long rightCommon = n-min(i,idx)-1-leftUnCommon;
            ans += 1LL*leftCommon*rightCommon;
            update(0,0,n-1,idx);
        }
        return ans;
    }
};