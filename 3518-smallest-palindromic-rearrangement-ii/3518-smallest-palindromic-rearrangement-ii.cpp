class Solution {
public:

    vector<int> freq;

    // long long ncr(int n,int r,long long limit)
    // {
    //     r=min(r,n-r);

    //     long long ans=1;

    //     for(int i=1;i<=r;i++)
    //     {
    //         ans=ans*(n-r+i)/i;

    //         if(ans>=limit)
    //             return limit;
    //     }

    //     return ans;
    // }

    long long ncr(int n,int r,long long limit){
        if(r<0 || r>n) return 0;

        r=min(r,n-r);

        long long ans=1;

        for(int i=1;i<=r;i++){
            long long num=n-r+i;
            long long den=i;

            long long g=__gcd(num,den);
            num/=g;
            den/=g;

            g=__gcd(ans,den);
            ans/=g;
            den/=g;


            if(ans>limit/num)
                return limit;

            ans*=num;
        }

        return min(ans,limit);
    }

    int find(int n,int k){
        int ans = 1;
        for(char ch = 'a'; ch<='z'; ch++){
            if(freq[ch-'a']==0){
                continue;
            }
            int ways = ncr(n,freq[ch-'a'],k);
            if(ans>k/ways) return k;
            ans *= ways;
            n -= freq[ch-'a'];
        }
        return ans;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.size();
        if(n==1){
            if(k==1) return s;
            return "";
        }
        freq.resize(26);
        for(int i = 0; i<n/2; i++){
            freq[s[i]-'a']++;
        }
        string s1 = "";
        int len = n/2;
        char ch = 'a';
        while(ch<='z' && len){
            if(freq[ch-'a']==0){
                ch++;
                continue;
            }
            freq[ch-'a']--;
            int cnt = find(len-1,k);
            if(cnt<k){
                k -= cnt;
                freq[ch-'a']++;
                ch++;
            }
            else{
                s1 += ch;
                len--;
                ch = 'a';
            }
        }
        if(len!=0) return "";
        string str = s1;
        if(n%2!=0) s1 += s[n/2];
        reverse(str.begin(),str.end());
        s1 += str;
        return s1;
    }
};