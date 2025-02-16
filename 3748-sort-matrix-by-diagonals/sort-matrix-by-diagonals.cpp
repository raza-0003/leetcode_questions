#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mpp[i-j].push_back(grid[i][j]);
            }
        }
        // sorting each diagoal element 
        for(auto &it:mpp){
            if(it.first < 0){
                // sort in the increasing order
                sort(it.second.begin(),it.second.end());
            }
            else{
                // sort in the decreasing order
                sort(it.second.rbegin(),it.second.rend());
            }
        }
        // now put the element in the matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j] = mpp[i-j].front();
                mpp[i-j].erase(mpp[i-j].begin());
            }
        }
        return grid;

    }
};