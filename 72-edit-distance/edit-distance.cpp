class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if (n == 0) return m;
        if (m == 0) return n;
        vector<int>prev(m+1,0),curr(m+1,0);
        for(int j=0;j<=m;j++) prev[j] = j;
        for(int ind1=1;ind1<=n;ind1++){
            curr[0] = ind1;
            for(int ind2=1;ind2<=m;ind2++){
                if(word1[ind1-1] == word2[ind2-1]){
                    curr[ind2] =  0 + prev[ind2-1];
                }
                else{
                    curr[ind2] =  1 + min({prev[ind2]// delete
                                        ,curr[ind2-1]         // insert
                                        ,prev[ind2-1]});    // replace
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};