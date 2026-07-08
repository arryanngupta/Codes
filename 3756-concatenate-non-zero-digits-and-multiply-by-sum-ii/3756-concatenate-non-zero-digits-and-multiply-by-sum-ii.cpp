class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.size();
        int mod = 1e9 + 7;

        vector<pair<long long,long long>> prefix(m+1);
        vector<int> nonZero(m+1, 0);

        long long sum = 0;
        long long str = 0;
        int cnt = 0;

        for (int i = 0; i < m; i++){
            if (s[i] != '0') {
                int d = s[i] - '0';
                sum += d;
                str = (str * 10 + d) % mod;
                cnt++;
            }
            nonZero[i+1] = cnt;
            prefix[i+1] = {str, sum};
        }

        vector<long long> pow10(m+1, 1);
        for(int i = 1; i <= m; i++){
            pow10[i] = (pow10[i-1] * 10) % mod;
        }
        vector<int> ans;
        for (auto &it : queries){
            int l = it[0], r = it[1];

            long long sumRange = prefix[r+1].second - prefix[l].second;

            long long left = prefix[l].first;
            long long right = prefix[r+1].first;

            int len = nonZero[r+1] - nonZero[l];

            long long x =
                (right - (left * pow10[len]) % mod + mod) % mod;   

            long long answer = (x * sumRange) % mod;
            if (answer < 0) answer += mod;                         

            ans.push_back((int)answer);
        }

        return ans;
    }
};
