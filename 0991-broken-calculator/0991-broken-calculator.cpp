class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int cnt = 0;
        while(target>startValue){
            if(target%2==0){
                cnt++;
                target /= 2;
            }
            else{
                target++;
                cnt++;
            }
        }
        return cnt+abs(target-startValue);
    }
};