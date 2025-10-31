class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int>mpp;
        vector<int>ans;
        for(auto it:nums){
            mpp[it]++;
            if(mpp[it] == 2){
                ans.push_back(it);
            }
        }
        return ans;
        
    }
};