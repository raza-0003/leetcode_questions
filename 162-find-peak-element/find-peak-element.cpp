class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int left = (mid-1+n)%n;
            int right = (mid+1)%n;
            if(nums[mid] > nums[left] && nums[mid] > nums[right]){
                return mid;
            }
            else if(nums[right] > nums[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};