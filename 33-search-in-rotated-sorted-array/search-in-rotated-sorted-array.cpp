class Solution {
public:
    int min_ind(vector<int>&arr){
        int n = arr.size();
        int low = 0;
        int high = n-1;
        if(n == 1) return 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[low] <= arr[high]) return low;
            int prev = (mid-1+n)%n;
            int next = (mid+1)%n;
            if(arr[mid] <= arr[prev] && arr[mid] <= arr[next]){
                return mid;
            }
            else if(arr[low] <= arr[mid]){
                // left wala part is sorted move to right side
                low = mid + 1;
            }
            else if(arr[mid] <= arr[high]){
                high = mid - 1;
            }
        }
        return 0;
    }
    int BS(vector<int>nums,int low,int high,int target){
        int n = nums.size();
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int piv_ind = min_ind(nums);
        int n = nums.size();
        if(nums[piv_ind] == target) return piv_ind;
        int l_ind = BS(nums,0,piv_ind-1,target);
        if(l_ind != -1) return l_ind;
        int r_ind = BS(nums,piv_ind,n-1,target);
        if(r_ind!=-1) return r_ind;
        return -1;
    }
};