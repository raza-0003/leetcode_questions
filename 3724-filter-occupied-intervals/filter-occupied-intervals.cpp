class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        vector<vector<int>>ans;
        for(auto it:occupiedIntervals){
            if(ans.empty() || ans.back()[1] + 1 < it[0]){
                ans.push_back(it);
            }
            else{
                ans.back()[1] = max(ans.back()[1],it[1]);
            }
        }
        if(ans.empty()) return {{}};
        vector<vector<int>>ans1;
        for(auto it:ans){
            int st = it[0];
            int end = it[1];
            if(freeStart > end || freeEnd < st){
                ans1.push_back({st,end});
            }
            else{
                if(st < freeStart){
                    ans1.push_back({st,freeStart-1});
                }
                if(end > freeEnd){
                    ans1.push_back({freeEnd+1,end});
                }
            }   
        }
        return ans1;
    }
};