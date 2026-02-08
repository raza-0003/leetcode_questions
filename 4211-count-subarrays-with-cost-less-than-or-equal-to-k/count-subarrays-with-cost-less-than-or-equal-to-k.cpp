class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        deque<int> mn,mx;
        long long ans = 0, l = 0;
        for(long long r = 0; r < nums.size(); r++){
            while(!mn.empty() && nums[mn.back()] >= nums[r]) mn.pop_back();
            while(!mx.empty() && nums[mx.back()] <= nums[r]) mx.pop_back();
            mn.push_back(r);
            mx.push_back(r);
            while((1LL * (nums[mx.front()] - nums[mn.front()]) * (r-l + 1)) > k){
                if(l == mn.front()) mn.pop_front();
                if(l == mx.front()) mx.pop_front();;
            l++;
            }
            ans += ((r-l)+1);
        }
        return ans;
    }
};