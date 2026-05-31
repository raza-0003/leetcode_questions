class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                cnt++;
            }
        }
        nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());
        for(int i=0;i<cnt;i++){
            nums.push_back(0);
        }
    }
};