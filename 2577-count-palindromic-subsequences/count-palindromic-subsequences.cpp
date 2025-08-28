class Solution {
public:
  int countPalindromes(string s) {
    const int MOD = 1e9 + 7;
    const int P = 5;
    long ans = 0;

    for (char a = '0'; a <= '9'; ++a)
      for (char b = '0'; b <= '9'; ++b) {
        vector<char> pattern = {a, b, '.', b, a};
        vector<long> dp(P + 1);
        dp[P] = 1;
        for (char c : s)
          for (int i = 0; i < P; ++i)
            if (pattern[i] == '.' || pattern[i] == c)
              dp[i] = (dp[i] + dp[i + 1]) % MOD;
        ans = (ans + dp[0]) % MOD;
      }

    return ans;
  }
};
