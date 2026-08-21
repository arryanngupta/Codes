class Solution {
public:

    int check(int i,int j,int k,int l,vector<vector<int>>& points){
        int n = points.size();
        vector<vector<int>> a;
        a.push_back(points[i]);
        a.push_back(points[j]);
        a.push_back(points[k]);
        a.push_back(points[l]);
        sort(a.begin(),a.end());
        if(a[0][0]!=a[1][0] || a[2][0]!=a[3][0]) return -1;
        if(a[0][1]!=a[2][1] || a[1][1]!=a[3][1]) return -1;

        for(int idx = 0; idx<n; idx++){
            if(idx==i || idx==j || idx==k || idx==l) continue;
            int x = points[idx][0],y = points[idx][1];
            if(x>=a[0][0] && x<=a[2][0] && y>=a[0][1] && y<=a[1][1]) return -1;
        }
        return (a[2][0]-a[0][0])*(a[1][1]-a[0][1]);
    }

    int maxRectangleArea(vector<vector<int>>& points) {
        int n = points.size(),maxi = -1;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                for(int k = j+1; k<n; k++){
                    for(int l = k+1; l<n; l++){
                        maxi = max(maxi,check(i,j,k,l,points));
                    }
                }
            }
        }
        return maxi;
    }
};