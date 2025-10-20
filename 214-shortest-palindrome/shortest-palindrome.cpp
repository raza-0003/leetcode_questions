class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        int end = n - 1;
        int j = 0;

        // Find the longest palindrome starting from index 0
        for (int i = end; i >= 0; i--) {
            if (s[i] == s[j]) j++;
        }

        // If the entire string is palindrome
        if (j == n) return s;

        string suffix = s.substr(j);  // part that is not palindrome
        string prefix = s.substr(0, j);

        reverse(suffix.begin(), suffix.end());
        // Recursively call for the prefix part to handle nested cases
        return suffix + shortestPalindrome(prefix) + s.substr(j);
    }
};
