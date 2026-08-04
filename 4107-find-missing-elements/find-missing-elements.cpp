class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        int l = INT_MAX;
        int r = INT_MIN;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            l = min(l,nums[i]);
            r = max(r,nums[i]);
            st.insert(nums[i]);
        }
        for(int i=l+1;i<r;i++){
            if(st.find(i) == st.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};