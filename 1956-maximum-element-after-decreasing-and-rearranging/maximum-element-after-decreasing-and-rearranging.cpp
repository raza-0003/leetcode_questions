class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        int mx = 1;
        sort(arr.begin(),arr.end());
        for(int i=1;i<n;i++){
            mx = min(arr[i],mx+1);
        }
        return mx;
        
    }
};