class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        int cnt2 = 0;
        for(int i=0;i<n;i++){
            vector<int>temp;
            int cnt = 0;
            for(int j=i;j<n;j++){
                if(nums[j] == target){
                    cnt++;
                }
                if(cnt > (j-i+1) / 2) cnt2++;
            }
           
        }
        return cnt2;
    }
};