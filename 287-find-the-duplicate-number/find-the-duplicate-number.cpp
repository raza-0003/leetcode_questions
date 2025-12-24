class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int dup;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            if(!mpp[nums[i]]){
                mpp[nums[i]]++;
            }
            else{
                return nums[i];
            }
        }
        return 0;
        
    }
};