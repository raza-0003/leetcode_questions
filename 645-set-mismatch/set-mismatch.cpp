class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dup_num;
        int miss_num = 0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(nums[i-1] == nums[i]){
                dup_num = nums[i];
                miss_num = miss_num ^ nums[i-1];
                i++;
            }
            else{
                miss_num = miss_num ^ nums[i-1];
            }
        }
        if(nums[n-1] != dup_num) miss_num = miss_num ^ nums[n-1];
        for(int i=1;i<=n;i++){
            miss_num = i ^ miss_num;
        }
        return {dup_num,miss_num};

        
    }
};