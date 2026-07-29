class Solution {
public:

    vector<int> freq;

    long long ncr(int n,int r,long long k){
        long long ans = 1;
        for(int i = 1; i<=min(n-r,r); i++){
            ans = (ans*(n-i+1))/i;
            if(ans>=k) return (int)k;
        }
        return (int) ans;
    }

    int find(int n,long long k){
        long long ans = 1;
        for(char ch = 'a'; ch<='z'; ch++){
            if(freq[ch-'a']==0){
                continue;
            }
            long long ways = ncr(n,freq[ch-'a'],k);
            if(ways>=k || 1LL*ans*ways>=k) return (int)k;
            ans *= ways;
            n -= freq[ch-'a'];
        }
        return (int)ans;
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