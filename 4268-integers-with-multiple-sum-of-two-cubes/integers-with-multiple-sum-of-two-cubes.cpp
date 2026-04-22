class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int,int>mpp;
        vector<int>ans;
        int x = cbrt(n);
        for(int i=1;i<=x;i++){
            for(int j=i;j<=x;j++){
                long long sum = pow(i,3) + pow(j,3);
                if(sum > n) break;
                mpp[sum]++;
            }
        }
        for(auto [it,freq]:mpp){
            if(freq >= 2){
                ans.push_back(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};