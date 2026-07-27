class Solution {
public:
    bool judgeSquareSum(int c) {
        vector<int> a;
        for(int i = 0; 1LL*i*i<=c; i++){
            a.push_back(i);
        }
        int i = 0,j = a.size()-1;
        while(i<=j){

            if((1LL*a[i]*a[i]+1LL*a[j]*a[j])>c){
                j--;
            }
            else if((1LL*a[i]*a[i]+1LL*a[j]*a[j])<c){
                i++;
            }
            else return true;
        }
        return false;
    }
};