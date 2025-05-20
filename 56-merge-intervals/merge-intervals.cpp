class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        if(intervals.size() == 0){
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        vector<int>tempintervals = intervals[0];
        for(auto it:intervals){
            if(it[0] <= tempintervals[1]){
                tempintervals[1] = max(it[1],tempintervals[1]);

            }
            else{
                ans.push_back(tempintervals);
                tempintervals = it;
            }
        }
        ans.push_back(tempintervals);
        return ans;        
    }
};