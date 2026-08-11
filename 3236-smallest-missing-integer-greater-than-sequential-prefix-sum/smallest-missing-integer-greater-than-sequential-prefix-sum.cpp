class Solution {
public:
    int missingInteger(vector<int>& nums) {

        int n = nums.size();

        // Find sum of longest sequential prefix
        int sum = nums[0];

        for(int i = 1; i < n; i++) {

            if(nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            }
            else {
                break;
            }
        }

        // Store all numbers in the array
        unordered_set<int> st;

        for(int x : nums) {
            st.insert(x);
        }

        // Find smallest missing number >= sum
        while(st.find(sum) != st.end()) {
            sum++;
        }

        return sum;
    }
};