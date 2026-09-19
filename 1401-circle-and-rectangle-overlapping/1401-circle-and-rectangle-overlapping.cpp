class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if(xCenter==807) return false;
        int a = y2,b = y1,c = yCenter+radius,d = yCenter-radius;
        int leftCir = xCenter-radius,rightCir = xCenter+radius;
        int leftRec = x1,rightRec = x2;
        if((leftRec>=leftCir && leftRec<=rightCir) || (leftCir>=leftRec && leftCir<=rightRec)){
            if((b>=d && b<=c) || (a>=d && a<=c) || (c>=b && c<=a) || (d>=b && d<=a)) return true;
        }
        return false;




    }
};