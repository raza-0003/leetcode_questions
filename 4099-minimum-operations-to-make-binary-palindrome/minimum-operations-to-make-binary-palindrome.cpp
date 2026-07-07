class Solution {
public:
    bool isPalindrome(int n){
        if(n == 1 || n == 0) return true;
        int temp = n;
        int x = 0;
        while(temp){
            int d = temp & 1;
            x = (x << 1)  | d;
            temp = temp / 2;
        }
        return x == n;
    }
    vector<int> minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int k = 0;
            while(true) {
                if (isPalindrome(nums[i] - k)) {
                    ans[i] = k;
                    break;
                } else if (isPalindrome(nums[i] + k)) {
                    ans[i] = k;
                    break;
                }
                k++;
            }
        }
        return ans;
    }
};