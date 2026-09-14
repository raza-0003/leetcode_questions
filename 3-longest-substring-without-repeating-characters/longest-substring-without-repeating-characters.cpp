class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int>mpp;
        int i = 0;
        int j = 0;
        int maxi = 0;
        while(j < n){
            mpp[s[j]]++;
            while(j-i+1 > mpp.size()){
                mpp[s[i]]--;
                if(mpp[s[i]] == 0) mpp.erase(s[i]);
                i++;
            }
            maxi = max(maxi,j-i+1);
            j++;

        }
        return maxi;
    }
};