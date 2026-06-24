class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0) return false;
        unordered_map<int,int> mpp;
        for(auto it: hand) mpp[it]++;
        sort(hand.begin(),hand.end());
        int i = 0;
        while(i<n){
            int no = hand[i],cnt = 0;
            while(cnt<groupSize && mpp.count(no)){
                cnt++;
                mpp[no]--;
                if(mpp[no]==0) mpp.erase(no);
                no++;
            }
            if(cnt!=groupSize) return false;
            while(i<n && !mpp.count(hand[i])) i++;
        }
        return true;
    }
};