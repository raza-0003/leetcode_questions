class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int maxLen = 0;
        // creating the unordered_set to evaluate the distinct digit
        unordered_set<char>charSet;
        for(int right = 0; right<n;right++){
            // keep checking until we got the distict charsets
            while(charSet.find(s[right]) != charSet.end()){
                charSet.erase(s[left]);
                left++;
            }
            //adding distinct char into the charSet
            charSet.insert(s[right]);
            maxLen = max(maxLen,right-left+1);
        }
        return maxLen;
    }
};