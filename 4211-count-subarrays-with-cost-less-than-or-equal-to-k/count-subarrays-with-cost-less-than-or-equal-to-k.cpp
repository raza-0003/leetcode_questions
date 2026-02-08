class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        multiset<int>s;
        int i=0;
        int j=0;
        long long ans = 0;
        int n = nums.size();
        while(j < n){
            s.insert(nums[j]);
            while(i<= j && ((*s.rbegin()-(*s.begin())) * 1LL * s.size() > k)){
                s.erase(s.find(nums[i]));
                i++;
            }
            ans += (j-i+1);
            j++;
        }
        return ans;
    }
};