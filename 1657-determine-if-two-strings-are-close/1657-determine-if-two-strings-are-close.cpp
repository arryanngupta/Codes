class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        vector<int> freq1(26),freq2(26);
        for(auto it: word1){
            freq1[it-'a']++;
        }
        for(auto it: word2){
            freq2[it-'a']++;
        }
        for(int i = 0; i<26; i++){
            int curr = freq1[i],need = freq2[i];
            if(curr==need) continue;
            if(curr==0 || need==0) return false;
            int flag = 0;
            for(int j = i+1; j<26; j++){
                if(freq1[j]==need){
                    swap(freq1[i],freq1[j]);
                    flag = 1;
                    break;
                }
            }
            if(flag==0) return false;
        }
        cout << "HI";
        return freq1==freq2;
    }
};
