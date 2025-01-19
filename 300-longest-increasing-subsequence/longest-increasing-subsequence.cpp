class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>prev(n+1,0),curr(n+1,0);
        for(int index=n-1;index>=0;index--){
            for(int prevInd=index-1;prevInd>=-1;prevInd--){
                int notTake = prev[prevInd+1];
                int take = 0;
                if(prevInd ==-1 || nums[index] > nums[prevInd]){
                    take = 1 + prev[index+1];
                }
                curr[prevInd+1] = max(take,notTake);
            }
            prev = curr;
        }
        return prev[0];
    }
};