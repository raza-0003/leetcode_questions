class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();  // n--> rows
        int m = matrix[0].size();  // m--> cols
        vector<int>row(n,1);
        vector<int>cols(m,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                   row[i]=0;
                   cols[j]=0;
                }
            }
        }
        // making all the arrays to zero
        for(int i=0;i<n;i++){
            if(row[i]==0){
                for(int j=0;j<m;j++){
                    matrix[i][j] = 0;
                }
            }
        }
        // making all the column to zero
        for(int i=0;i<m;i++){
            if(cols[i] == 0){
                for(int j=0;j<n;j++){
                    matrix[j][i] = 0;
                }
            }

        }
    }
};