class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int>s_nums(nums);
        sort(s_nums.begin(),s_nums.end());
        if(nums == s_nums) return true;
        int n = nums.size();
        for(int i=0;i<n;i++){
            // i-->denotes array is denote by i positions
            bool flag = true;
            for(int j=0;j<n;j++){
                if(s_nums[j] != nums[(i+j)%n]){
                    flag = false;
                    break;
                } 
            }
            if(flag) return true;
        }
        return false;
    }
};