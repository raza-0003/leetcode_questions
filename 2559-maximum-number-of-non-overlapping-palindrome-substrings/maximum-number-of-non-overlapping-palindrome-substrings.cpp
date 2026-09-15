class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // pal[i][j] = true if s[i...j] is palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Build palindrome table
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                if (len == 1) {
                    pal[i][j] = true;
                }
                else if (len == 2) {
                    pal[i][j] = (s[i] == s[j]);
                }
                else {
                    pal[i][j] = (s[i] == s[j]) && pal[i + 1][j - 1];
                }
            }
        }

        // dp[i] = maximum number of valid palindromes
        // from s[0...i]
        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++) {

            // Don't choose a palindrome ending at i
            if (i > 0) {
                dp[i] = dp[i - 1];
            }

            // Try every palindrome s[j...i]
            for (int j = 0; j <= i; j++) {

                int len = i - j + 1;

                if (len >= k && pal[j][i]) {

                    int previous = (j == 0 ? 0 : dp[j - 1]);

                    dp[i] = max(dp[i], previous + 1);
                }
            }
        }

        return dp[n - 1];
    }
};