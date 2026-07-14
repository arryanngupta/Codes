class Solution {
public:

    unordered_map<int,char> mpp;

    string hexaDeci(long long sq){
        string s = "";
        while(sq!=0){
            int digit = sq%16;
            sq = sq/16;
            char ch;
            if(digit>=10) ch = mpp[digit];
            else ch = digit+'0';
            s += ch;
        }
        reverse(s.begin(),s.end());
        return s;
    }

    string hexaTri(long long cube){
        string s = "";
        while(cube!=0){
            int digit = cube%36;
            cube = cube/36;
            char ch;
            if(digit>=10) ch = mpp[digit];
            else ch = digit+'0';
            s += ch;
        }
        reverse(s.begin(),s.end());
        return s;
    }

    string concatHex36(int n) {
        long long num = n;
        long long sq = n*n,cube = n*n*n;
        char ch = 'A';
        for(int i = 10; i<36; i++){
            mpp[i] = ch;
            ch++;
        }
        string hD = hexaDeci(sq);
        string hT = hexaTri(cube);
        return (hD+hT);
    }
};