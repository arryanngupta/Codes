class Solution {
public:

    vector<int> segTree;
    int maxi = 1e5;

    int find(int i,int l,int r,int left,int right){
        if(r<left || l>right || l>r) return 0;
        if(l>=left && r<=right) return segTree[i];
        int mid = (l+r)/2;
        return find(2*i+1,l,mid,left,right)+find(2*i+2,mid+1,r,left,right);
    }

    void update(int i,int l,int r,int idx){
        if(l==r){
            segTree[i]++;
            return ;
        }
        int mid = (l+r)/2;
        if(idx<=mid) update(2*i+1,l,mid,idx);
        else update(2*i+2,mid+1,r,idx);
        segTree[i] = segTree[2*i+1]+segTree[2*i+2];
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        segTree.resize(4*maxi);
        vector<int> ans(n);
        int mini = *min_element(nums.begin(),nums.end());
        mini = abs(mini);
        for(int i = n-1; i>=0; i--){
            ans[i] = find(0,0,maxi,0,nums[i]+mini-1);
            update(0,0,maxi,nums[i]+mini);
        }
        return ans;
    }
};