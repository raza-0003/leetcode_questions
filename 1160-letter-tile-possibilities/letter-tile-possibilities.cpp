class Solution {
public:
    int dfs(unordered_map<char,int>&mpp){
        int sum = 0;
        for(auto &it: mpp){
            if(it.second == 0) continue;
            // using this character
            it.second--;
            sum++;
            // recursively try the subsequent position 
            sum += dfs(mpp);
            // back tracking 
            it.second++;

        }
        return sum;
    }
    int numTilePossibilities(string tiles) {
        unordered_map<char,int>mpp;
        for(char ch:tiles){
            mpp[ch]++;
        }
        return dfs(mpp);
    }
};