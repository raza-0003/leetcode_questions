class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long n = nums.size();
        long long maxi = INT_MIN;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k = j+1;k<n;k++){
                    long long  value = (long long)(nums[i]-nums[j]) * nums[k];
                    if(value > maxi){
                        maxi  = value;
                    }
                }
            }
        }
        if(maxi<0) return 0;
        return maxi;
        
    }
};