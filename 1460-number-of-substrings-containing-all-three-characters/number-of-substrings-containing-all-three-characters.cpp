class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        vector<int>ch(3,0);
        int left = 0;
        for(int i=0;i<n;i++){
            ch[s[i]-'a']++;
            while(ch[0] > 0 && ch[1] > 0 && ch[2] > 0){
                ans += n - i;
                ch[s[left]-'a']--;
                left++;
            }

        }
        return ans;
    }
};