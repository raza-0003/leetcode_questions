class Solution {
public:
    int getLucky(string s, int k) {
        int n = s.size();
        unordered_map<char,int>mpp;
        int i=1;
        for(char ch='a';ch<='z';ch++){
            mpp[ch] = i;
            i++;
        }
        string result;
        for(int f=0;f<n;f++){
            int num = mpp[s[f]];
            result += to_string(num);
        }
        for(int l=1;l<=k;l++){
            int ans = 0;
            for(int j=0;j<result.size();j++){
                ans += result[j] - '0';
            }
            result = to_string(ans);
        }
        return stoi(result);
    }
};