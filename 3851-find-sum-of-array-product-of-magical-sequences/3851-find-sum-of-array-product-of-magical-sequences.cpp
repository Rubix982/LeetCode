// ChatGPT generated, I need to learn a lot


const int MOD = 1e9 + 7;

// Fast modular exponentiation
long long mod_pow(long long base, int exp) {
    long long res = 1;
    while (exp) {
        if (exp & 1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

// Precompute factorials and combinations up to m
struct Comb {
    vector<long long> fact, invfact;
    Comb(int n) {
        fact.resize(n + 1);
        invfact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
        invfact[n] = mod_pow(fact[n], MOD - 2);
        for (int i = n; i > 0; i--) invfact[i - 1] = invfact[i] * i % MOD;
    }
    long long C(int n, int r) const {
        if (r < 0 || r > n) return 0;
        return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
    }
};

class Solution {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();
        Comb comb(m);

        // Precompute nums[i]^c for all c = 0..m
        vector<vector<long long>> pow_nums(n, vector<long long>(m + 1, 1));
        for (int i = 0; i < n; i++) {
            for (int c = 1; c <= m; c++) {
                pow_nums[i][c] = pow_nums[i][c - 1] * nums[i] % MOD;
            }
        }

        // 3D DP: dp[carry][remaining][ones]
        vector<vector<vector<long long>>> dp(m + 1,
            vector<vector<long long>>(m + 1, vector<long long>(k + 1, 0)));

        dp[0][m][0] = 1;  // start state

        for (int j = 0; j < n; j++) {
            vector<vector<vector<long long>>> ndp(m + 1,
                vector<vector<long long>>(m + 1, vector<long long>(k + 1, 0)));

            for (int carry = 0; carry <= m; carry++) {
                for (int rem = 0; rem <= m; rem++) {
                    for (int ones = 0; ones <= k; ones++) {
                        long long cur = dp[carry][rem][ones];
                        if (!cur) continue;

                        // Try all possible counts for index j
                        for (int c = 0; c <= rem; c++) {
                            int total = carry + c;
                            int bit = total & 1;
                            int newOnes = ones + bit;
                            if (newOnes > k) continue;

                            int carryOut = total >> 1;
                            int newRem = rem - c;

                            long long add = cur;
                            add = add * comb.C(rem, c) % MOD;
                            add = add * pow_nums[j][c] % MOD;

                            ndp[carryOut][newRem][newOnes] += add;
                            if (ndp[carryOut][newRem][newOnes] >= MOD)
                                ndp[carryOut][newRem][newOnes] -= MOD;
                        }
                    }
                }
            }

            dp.swap(ndp);
        }

        // After all bits processed, remaining = 0
        long long ans = 0;
        for (int carry = 0; carry <= m; carry++) {
            int extraOnes = __builtin_popcount(carry);
            for (int ones = 0; ones <= k; ones++) {
                if (ones + extraOnes == k) {
                    ans = (ans + dp[carry][0][ones]) % MOD;
                }
            }
        }

        return ans;
    }
};