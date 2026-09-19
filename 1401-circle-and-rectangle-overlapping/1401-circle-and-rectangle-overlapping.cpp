class Solution {
public:

    int find(int x1,int y1,int x2,int y2){
        return sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
    }

    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x = 0,y = 0;
        if(x1>xCenter) x = x1;
        else if(x2<xCenter) x = x2;
        else x = xCenter;
        if(y1>yCenter) y = y1;
        else if(y2<yCenter) y = y2;
        else y = yCenter;
        int dist = find(x,y,xCenter,yCenter);
        return dist<=radius;
    }
};