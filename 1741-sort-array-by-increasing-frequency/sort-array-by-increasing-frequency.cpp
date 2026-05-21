class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minH;
        for(auto it:mpp){
            minH.push({it.second,-it.first});
        }
        int ind=0;
        vector<int>ans(n);
        while(!minH.empty()){
            auto it = minH.top();
            minH.pop();
            int freq = it.first;
            int elem = it.second;
            for(int i=0;i<freq;i++){
                ans[ind] = -elem;
                ind++;
            }
        }
        return ans;
    }
};