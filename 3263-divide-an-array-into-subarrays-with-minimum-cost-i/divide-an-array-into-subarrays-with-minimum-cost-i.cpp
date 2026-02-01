class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int first = INT_MAX;
        int second = INT_MAX;
        for(int i=1;i<n;i++){
            int x = nums[i];
            if(x < first){
                second = first;
                first = x;
            }
            else if(x < second){
                second = x;
            }
        }
        return nums[0] + first + second;
    }
};