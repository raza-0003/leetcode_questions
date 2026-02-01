class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int min_cost = 1e9;
        for(int i=0;i<n-2;i++){ 
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    int cost =nums[0] + nums[j] + nums[k];
                    min_cost = min(cost,min_cost);
                }
            }
        }
        return min_cost;
    }
};