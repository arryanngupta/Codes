class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(),maxi = 1;
        unordered_map<double,int> mpp;
        for(int i = 0; i<n; i++){
            int x1 = points[i][0],y1 = points[i][1];
            for(int j = 0; j<n; j++){
                if(i==j) continue;
                int x2 = points[j][0],y2 = points[j][1];
                if(x2-x1==0) continue;
                double m = (y2-y1)/(double)(x2-x1);
                if(mpp.find(m)==mpp.end()){
                    mpp[m] = 2;
                }
                else{
                    mpp[m]++;
                }
                maxi = max(maxi,mpp[m]);
            }
            mpp.clear();
        }
        mpp.clear();
        for(int i = 0; i<n; i++){
            int x1 = points[i][0],y1 = points[i][1];
            for(int j = 0; j<n; j++){
                if(i==j) continue;
                int x2 = points[j][0],y2 = points[j][1];
                if(x2-x1==0){
                    if(mpp.find(x1)==mpp.end()){
                        mpp[x1] = 2;
                    }
                    else{
                        mpp[x1]++;
                    }
                    maxi = max(maxi,mpp[x1]);
                }
            }
            mpp.clear();
        }
        return maxi;
    }
};