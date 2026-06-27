class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long,int>mpp;
        int mx = 0;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int ans = 1;
        if(mpp.count(1)){
            int cnt = mpp[1];
            ans = max(ans,cnt%2?cnt:cnt-1);
        }
        for(auto &[num,freq]:mpp){
            if(num == 1) continue;
            long long x = num;
            int len = 0;
            while(mpp.count(x) && mpp[x] >= 2){
                len += 2;
                if(x > 1e9) break;
                x = x * x;
            }
            if(mpp.count(x)){
                len++;
            }
            else{
                len--;
            }
            ans = max(ans,len);
        }
        return ans;

        
    }
};