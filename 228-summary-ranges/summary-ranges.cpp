class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        int left=0;
        int right=1;
        vector<string>ans;
        while(right < n){
            if(nums[right] == (nums[right-1] + 1)){
                // they are in consequitive
                right++;
            }
            else{
                if(right - left  > 1){
                    string temp = to_string(nums[left]) + "->" + to_string(nums[right-1]);
                    ans.push_back(temp);
                }
                else{
                    ans.push_back(to_string(nums[left]));
                }
                left = right;
                right++; 
            }
                
        }
        if(right - left > 1){
            ans.push_back(to_string(nums[left]) + "->" + to_string(nums[right-1]));
        }
        else{
            ans.push_back(to_string(nums[left]));
        }
        return ans;

    }
};