class Solution {
public:

    bool find(int start,vector<int>& stones,vector<int> &freq){
        int turn = 0,sum = 0;
        while(true){
            if(((sum+start)%3!=0) && freq[start]){
                sum+=start;
                freq[start]--;
                turn ^= 1;
            }
            else if((sum+(3-start))%3!=0 && freq[3-start]){
                sum += 3-start;
                freq[3-start]--;
                turn ^= 1;
            }
            else if(freq[0]){
                freq[0]--;
                turn ^= 1;
            }
            else{
                if(freq[0]==0 && freq[1]==0 && freq[2]==0) return false;
                return turn;
            }
        }
        return 1;
    }

    bool stoneGameIX(vector<int>& stones) {
        vector<int> freq(3);
        for(auto it: stones) freq[it%3]++;
        if(freq[1]==0 && freq[2]==0) return false;
        bool a = find(1,stones,freq);
        freq.assign(3,0);
        for(auto it: stones) freq[it%3]++;
        bool b = find(2,stones,freq);
        return a||b;
    }
};