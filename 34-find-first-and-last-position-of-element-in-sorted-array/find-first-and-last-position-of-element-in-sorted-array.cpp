class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        // lets find the first occr
        int f_ind = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                f_ind = mid;
                high = mid - 1;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        int l_ind = -1;
        low = 0;
        high = n-1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                l_ind = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target){
                low  = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        vector<int>ans;
        ans.push_back(f_ind);
        ans.push_back(l_ind);
        return ans;
    }
};