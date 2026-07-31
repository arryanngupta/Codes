class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0,b = 0,n = colors.size();
        if(n<=2) return false;
        int i = 0;
        while(i<n){
            if(colors[i]=='A'){
                int cnt = 0;
                while(i<n && colors[i]=='A'){
                    cnt++;
                    i++;
                }
                a += max(0,cnt-2);
            }
            else{
                int cnt = 0;
                while(i<n && colors[i]=='B'){
                    i++;
                    cnt++;
                }
                b += max(0,cnt-2);
            }
        }
        return (a>b);
    }
};