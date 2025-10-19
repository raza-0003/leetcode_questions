class Solution {
    public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>freq;
        for(int x:nums){
            int rem = ((x % value) + value) % value;
            freq[rem]++;
        }
        int mex = 0;
        while(true){
            int rem = mex % value;
            if(freq[rem] > 0){
                freq[rem]--;
                mex++;
            }
            else{
                return mex;
            }
        }
        return 0;
        
    }
};