class Solution {
public:
    int dp[2001][2001][2];
    static const int mod = 1000000007;

    int zigZagArrays(int n, int l, int r) {

        int r1 = r - l + 1;


        for (int prev = 1; prev <= r1; prev++) {
            dp[n][prev][0] = 1;
            dp[n][prev][1] = 1;
        }

        static int prefixSum1[2002];
        static int prefixSum2[2002];

        for (int idx = n - 1; idx >= 0; idx--) {

            prefixSum1[0] = prefixSum1[1] = 0;
            prefixSum2[0] = prefixSum2[1] = 0;

            int sum0 = 0, sum1 = 0;

            for (int val = 1; val <= r1; val++) {

                sum0 += dp[idx + 1][val][0];
                if (sum0 >= mod) sum0 -= mod;
                prefixSum1[val + 1] = sum0;

                sum1 += dp[idx + 1][val][1];
                if (sum1 >= mod) sum1 -= mod;
                prefixSum2[val + 1] = sum1;
            }

            for (int prev = r1; prev >= 1; prev--) {

                dp[idx][prev][1] = prefixSum1[prev];

                int x = prefixSum2[r1 + 1] - prefixSum2[prev + 1];
                if (x < 0) x += mod;
                dp[idx][prev][0] = x;
            }
        }

        int asc = 0, dsc = 0;

        for (int i = 1; i <= r1; i++) {

            asc += dp[1][i][1];
            if (asc >= mod) asc -= mod;

            dsc += dp[1][i][0];
            if (dsc >= mod) dsc -= mod;
        }

        int ans = asc + dsc;
        if (ans >= mod) ans -= mod;

        return ans;
    }
};