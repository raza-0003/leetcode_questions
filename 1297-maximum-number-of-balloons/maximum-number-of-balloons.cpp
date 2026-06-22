class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mpp;
        int n = text.size();
        for(int i=0;i<n;i++){
            mpp[text[i]]++;
        }
        int cnt = mpp['a'];
        if(cnt == 0) return 0;
        for(char ch='a';ch<='o';ch++){
            if(ch == 'a' || ch == 'b' || ch == 'l' || ch == 'o' || ch == 'n'){
                if(mpp.find(ch) != mpp.end()){
                    if(ch == 'a' || ch == 'b' || ch == 'n'){
                        cnt = min(cnt,mpp[ch]);
                    }
                    else{
                        if(mpp[ch] < 2) return 0;
                        cnt = min(cnt,mpp[ch]/2);
                    }
                }
                else{
                    return 0;
                }
            }
        }
        return cnt;

    }
};