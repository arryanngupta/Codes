class Solution {
public:

    int find(vector<int>& nums1, vector<int>& nums2,int flag){
        int n = nums1.size(),cnt = flag;
        int a = nums1[n-1],b = nums2[n-1];
        if(flag){
            a = nums2[n-1];
            b = nums1[n-1];
        }
        for(int i = 0; i<n-1; i++){
            if((nums1[i]>a && nums2[i]>a) || (nums1[i]>a && nums1[i]>b)){
                return -1;
            }
            if((nums2[i]>b && nums1[i]>b) || (nums2[i]>b && nums2[i]>a)) return -1;
            if(nums1[i]>a || nums2[i]>b){
                cnt++;
            }
        }
        return cnt;
    }

    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int a = find(nums1,nums2,0);
        int b = find(nums1,nums2,1);
        if(a==-1) return b;
        else if(b==-1) return a;
        return min(a,b);
    }
};