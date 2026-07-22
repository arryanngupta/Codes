class NumArray {
public:
    vector<int> segTree;
    int len;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        len = n;
        segTree.resize(4*n);
        buildsegTree(0,0,n-1,nums);
    }

    void buildsegTree(int i,int l,int r,vector<int> &nums){
        if(l==r){
            segTree[i] = nums[l];
            return ;
        }
        int mid = (l+r)/2;
        buildsegTree(2*i+1,l,mid,nums);
        buildsegTree(2*i+2,mid+1,r,nums);
        segTree[i] = segTree[2*i+1]+segTree[2*i+2];
    }

    void updSegTree(int idx,int val,int i,int l,int r){
        if(l==r){
            segTree[i] = val;
            return ;
        }
        int mid = (l+r)/2;
        if(idx<=mid){
            updSegTree(idx,val,2*i+1,l,mid);
        }
        else{
            updSegTree(idx,val,2*i+2,mid+1,r);
        }
        segTree[i] = segTree[2*i+1]+segTree[2*i+2];
    }

    int recFind(int i,int l,int r,int left,int right){
        if(r<left || l>right) return 0;
        if(l>=left && r<=right) return segTree[i];
        int mid = (l+r)/2;
        return recFind(2*i+1,l,mid,left,right)+recFind(2*i+2,mid+1,r,left,right);
    }
    
    void update(int index, int val) {
        updSegTree(index,val,0,0,len-1);
    }
    
    int sumRange(int left, int right) {
        return recFind(0,0,len-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */