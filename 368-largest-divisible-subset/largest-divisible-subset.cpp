class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int maxi = 0;
        int lastInd = 0;
        vector<int>dp(n,1),hash(n);
        for(int index=1;index<n;index++){
            hash[index] = index;
            for(int prev = 0;prev<index;prev++){
                if(nums[index]%nums[prev] == 0 && dp[prev]+1>dp[index]){
                    dp[index] = 1 + dp[prev];
                    hash[index] = prev;
                }
            }
            if(dp[index]>maxi){
                lastInd = index;
                maxi = dp[index];
            }
        }
        vector<int>temp;
        temp.push_back(nums[lastInd]);
        while(hash[lastInd]!=lastInd){
            lastInd = hash[lastInd];
            temp.push_back(nums[lastInd]);
        }
        return temp;
    }
};