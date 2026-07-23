class Solution {
public:

    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(),tokens.end());
        int i = 0,j = n-1,ans = 0;
        while(i<=j){
            if(power>=tokens[i]){
                ans++;
                power -= tokens[i];
                i++;
            }
            else{
                if(i==j || ans==0) break;
                power += tokens[j];
                ans--;
                j--;
            }
        }
        return ans;
    }
};