class Solution {
public:
    int countPalindromicSubsequence(string s) {
     int n = s.size();

    // Array to store the first and last occurrence of each character
    vector<int> first(26, -1), last(26, -1);

    // Fill first and last occurrence for each character
    for (int i = 0; i < n; ++i) {
        if (first[s[i] - 'a'] == -1) {
            first[s[i] - 'a'] = i;
        }
        last[s[i] - 'a'] = i;
    }

    int result = 0;

    // For each character as the outer characters of the palindrome
    for (int ch = 0; ch < 26; ++ch) {
        if (first[ch] != -1 && last[ch] > first[ch]) {
            unordered_set<char> uniqueMiddle; // To store unique middle characters
            for (int i = first[ch] + 1; i < last[ch]; ++i) {
                uniqueMiddle.insert(s[i]);
            }
            result += uniqueMiddle.size(); // Add unique middle characters count
        }
    }

    return result;
    }
};