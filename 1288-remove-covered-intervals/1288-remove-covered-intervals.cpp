class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int n = intervals.size();
        for(int i = 1; i<n; i++){
            int a = ans.back()[0],b = ans.back()[1];
            int c = intervals[i][0],d = intervals[i][1];
            if((a>=c && b<=d) || (c>=a && d<=b)){
                ans.back()[0] = min(a,c);
                ans.back()[1] = max(b,d);
            }
            else{
                ans.push_back({c,d});
            }
        }
        return ans.size();
    }
};