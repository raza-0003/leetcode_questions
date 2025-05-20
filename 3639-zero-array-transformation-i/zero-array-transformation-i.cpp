class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n+1, 0);
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            diff[l]++; 
            if (r + 1 < n)
                diff[r + 1]--; 
        }

        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt += diff[i];
            if (nums[i] > cnt)
                return false;
        }
        return true;
    }
};