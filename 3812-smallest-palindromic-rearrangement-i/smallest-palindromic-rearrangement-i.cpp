class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if(n == 1) return s;
        vector<int>ch(26,0);
        for(int i=0;i<n;i++){
            ch[s[i]-'a']++;
        }
        vector<char>front;
        vector<char>back;
        deque<char>dq;
        char mid = '\0';
        for(int i=0;i<26;i++){
            if(ch[i]){
                while(ch[i] >= 2){
                    front.push_back('a' + i);
                    back.push_back('a' + i);
                    ch[i] -= 2;
                }
            }
            if(ch[i] == 1){
                mid = 'a' + i;
            }
        }
        string ans;
        int m = min(front.size(),back.size());
        for(int i=0;i<m;i++){
            ans += front[i];
        }
        if(mid){
            ans += mid;
        }
        for(int i=0;i<m;i++){
            ans += back[m-i-1];
        }
        return ans;
    }
};