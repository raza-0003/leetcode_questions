class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int>mpp;
        vector<int>ans;
        for(auto it:nums){
            mpp[it]++;
        }
        for(auto [num,freq]:mpp){
            if(freq == 2){
                ans.push_back(num);
            }
        }
        return ans;
        
    }
};