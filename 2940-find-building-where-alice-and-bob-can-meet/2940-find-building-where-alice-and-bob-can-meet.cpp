class Solution {
public:

    vector<int> segTree;

    void buildSegTree(int i,int l,int r,vector<int>& heights){
        if(l==r){
            segTree[i] = l;
            return ;
        }
        int mid = l+(r-l)/2;
        buildSegTree(2*i+1,l,mid,heights);
        buildSegTree(2*i+2,mid+1,r,heights);
        int leftMaxIdx = segTree[2*i+1],rightMaxIdx = segTree[2*i+2];
        if(heights[leftMaxIdx]>=heights[rightMaxIdx]){
            segTree[i] = leftMaxIdx;
        }
        else segTree[i] = rightMaxIdx;
    }

    int check(int i,int l,int r,int start,int end,vector<int>& heights){
        if(end<l || start>r || start>end) return -1;
        if(start>=l && end<=r) return segTree[i];
        int mid = (start+end)/2;
        int leftMaxIdx = check(2*i+1,l,r,start,mid,heights);
        int rightMaxIdx = check(2*i+2,l,r,mid+1,end,heights);
        if(leftMaxIdx==-1) return rightMaxIdx;
        if(rightMaxIdx==-1) return leftMaxIdx;
        if(heights[leftMaxIdx]>=heights[rightMaxIdx]){
            return leftMaxIdx;
        }
        return rightMaxIdx;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        segTree.resize(4*n,-1);   
        buildSegTree(0,0,n-1,heights);
        vector<int> res;
        for(auto it: queries){
            int a = min(it[0],it[1]);
            int b = max(it[0],it[1]);
            if(a==b || heights[b]>heights[a]){
                res.push_back(b);
                continue;
            }
            int low = b+1,high = n-1,ans = -1;
            while(low<=high){
                int mid = low+(high-low)/2;
                int maxIdx = check(0,low,mid,0,n-1,heights);
                if(maxIdx!=-1 && heights[maxIdx]>max(heights[a],heights[b])){
                    ans = maxIdx;
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};