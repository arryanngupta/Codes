class Solution {
public:

    bool overlap(int a,int b,int c,int d){
        if((b>=c && b<=d) || (d>=a && d<=b)) return true;
        return false;
    }

    int find(vector<int>& nums, int a, int b){
        int n = nums.size(),maxi = 0,sum = 0;
        int i = 0,j = 0;
        while(j<n-b){
            sum += nums[j];
            if(j-i+1==a){
                int x = j+1,y = x;
                int sum2 = 0;
                while(y<n){
                    sum2 += nums[y];
                    if(y-x+1==b){
                        maxi = max(maxi,sum+sum2);
                        sum2 -= nums[x];
                        x++;
                    }
                    y++;
                }
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return maxi;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(find(nums,firstLen,secondLen),find(nums,secondLen,firstLen));
    }
};