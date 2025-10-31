class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long ans = 1;
        int target = nums2[n];
        int mini = INT_MAX;
        bool flag = false;
        for(int i=0;i<n;i++){
            if((target <= nums1[i] && target >= nums2[i]) || (target <= nums2[i] && target >= nums1[i])){
                flag = true;
                break;
            }
        }
        for(int i=0;i<n;i++){
            ans += abs(nums1[i]-nums2[i]);
            if(!flag){
                int n = abs(target-nums1[i]);
                int m = abs(target-nums2[i]);
                mini = min(mini,min(n,m));
            }
        }
        if(!flag){
            return ans + mini;
        }
        return ans;


    }
};