class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        for(auto it:nums){
            mpp[it]++;
        }
        for(auto it:mpp){
            if(it.second > n/2 ){
                int elem = it.first;
                return elem;
            }
        }
        return 0;
        
    }
};