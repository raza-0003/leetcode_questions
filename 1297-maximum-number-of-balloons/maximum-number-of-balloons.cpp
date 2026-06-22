class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mpp;
        int n = text.size();
        for(int i=0;i<n;i++){
            mpp[text[i]]++;
        }
        return min({mpp['a'],mpp['b'],mpp['n'],mpp['l']/2,mpp['o']/2});

    }
};