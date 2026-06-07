class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]){
                return nums[mid];
            }
            // note: 1) if mid is odd --> left me and right me odd element honge. 2) if mid is even then left and right me even elems honge
            else if(mid % 2 == 1){
                // left and right me odd element honge
                if(nums[mid] == nums[mid-1]){
                    low = mid +1;
                }
                else{
                    high = mid-1;
                }
            }
            else{
                // left and right me even elements
                if(nums[mid] == nums[mid-1]){
                    high = mid-1;
                }
                else{
                    low = mid +1;
                }
            }
        }
        return -1;
    }
};