class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        int r = count(senate.begin(),senate.end(),'R');
        int d = n-r;
        vector<int> a(n);
        int i = 0;
        while(r && d){
            if(a[i]==0){
                if(senate[i]=='R'){
                    int j = i,cnt = 0;
                    while(cnt<n && (senate[j]!='D' || a[j]==1)){
                        j=(j+1)%n;
                        cnt++;
                    }
                    if(senate[j]=='D' && a[j]==0){
                        a[j] = 1;
                        d--;
                    }
                    else return "Radiant";
                }
                else{
                    int j = i,cnt = 0;
                    while(cnt<n && (senate[j]!='R' || a[j]==1)){
                        j=(j+1)%n;
                        cnt++;
                    }
                    if(senate[j]=='R' && a[j]==0){
                        a[j] = 1;
                        r--;
                    }
                    else return "Dire";
                }
            }
            i = (i+1)%n;
        }
        if(d) return "Dire";
        return "Radiant";
    }
};