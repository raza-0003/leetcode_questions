class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        for(auto num:nums){
            mpp[num]++;
        }
        for(int i=1;i<=n;i++){
            if(mpp.find(i) == mpp.end()){
                return i;
            }
        }
        return n+1;

    }
};