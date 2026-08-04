class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>prev;
        for(int r=0;r<numRows;r++){
            vector<int>temp(r+1,1);
            for(int c=1;c<r;c++){
                temp[c] = prev[c-1] + prev[c];
            }
            ans.push_back(temp);
            prev = temp;
        }
        return ans;
        
    }
};