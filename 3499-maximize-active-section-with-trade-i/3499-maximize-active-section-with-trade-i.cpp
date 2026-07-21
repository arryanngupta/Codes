class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        vector<int> leftZero(n),leftOne(n),rightZero(n),rightOne(n);
        int i = 0,cnt = 0;
        while(i<n){
            if(s[i]=='0'){
                cnt = 0;
                while(i<n && s[i]=='0'){
                    leftZero[i]=cnt;
                    cnt++;
                    i++;
                }
                if(i<n) leftZero[i] = cnt;
            }
            else{
                cnt = 0;
            }
            i++;
        }
        i = 0,cnt = 0;
        while(i<n){
            if(s[i]=='1'){
                cnt = 0;
                while(i<n && s[i]=='1'){
                    leftOne[i]=cnt;
                    cnt++;
                    i++;
                }
                if(i<n) leftOne[i] = cnt;
            }
            else{
                cnt = 0;
            }
            i++;
        }
        i = n-1,cnt = 0;
        while(i>=0){
            if(s[i]=='0'){
                cnt = 0;
                while(i>=0 && s[i]=='0'){
                    rightZero[i]=cnt;
                    cnt++;
                    i--;
                }
                if(i>=0) rightZero[i] = cnt;
            }
            else{
                cnt = 0;
            }
            i--;
        }
        i = n-1,cnt = 0;
        int one = 0;
        while(i>=0){
            if(s[i]=='1'){
                cnt = 0;
                while(i>=0 && s[i]=='1'){
                    rightOne[i]=cnt;
                    cnt++;
                    one++;
                    i--;
                }
                if(i>=0) rightOne[i] = cnt;
            }
            else{
                cnt = 0;
            }
            i--;
        }
        int maxi = 0;
        for(int i = 1; i<n-1; i++){
            if(s[i]=='0') continue;
            cnt = 0;
            int j = i;
            while(j<n && s[j]=='1'){
                cnt++;
                j++;
            }
            int lz = leftZero[i],rz = rightZero[j-1];
            if(lz && rz){
                int lo = leftOne[i-lz],ro = rightOne[j-1+rz];
                cnt += lo+ro;
                maxi = max(maxi,lz+rz+(j-i)+lo+ro+one-cnt);
            }
            i = j;
        }
        return max(maxi,one);
    }
};