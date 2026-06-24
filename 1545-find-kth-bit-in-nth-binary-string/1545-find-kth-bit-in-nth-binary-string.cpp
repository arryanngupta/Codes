class Solution {
public:

    vector<int> power;

    void findPow(){
        power.resize(21);
        power[0] = 1;
        for(int i = 1; i<=20; i++){
            power[i] = 2*power[i-1];
        }
    }

    char recFind(int n,int k){
        if(n==1 || k==1) return '0';
        int len = power[n]-1;
        if(k==(len/2)+1) return '1';
        int idx = (k>((len/2)+1))?len-k+1:k;
        char ch = recFind(n-1,idx);
        if(k>((len/2)+1)) return (1-(ch-'0'))+'0';
        return ch;
    }

    char findKthBit(int n, int k) {
        findPow();
        return recFind(n,k);
    }
};