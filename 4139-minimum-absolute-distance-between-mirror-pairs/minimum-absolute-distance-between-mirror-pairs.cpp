class Solution {
public:
    int rev(int n){
        int revNum = 0;
        while(n){
            revNum = revNum * 10 + (n % 10);
            n /= 10;
        }
        return revNum;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mp;
        int mini = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            // check if current exists as reverse before
            if(mp.count(nums[i])){
                mini = min(mini, i - mp[nums[i]]);
            }

            // store reverse of current
            int r = rev(nums[i]);
            mp[r] = i;
        }

        return mini == INT_MAX ? -1 : mini;
    }
};