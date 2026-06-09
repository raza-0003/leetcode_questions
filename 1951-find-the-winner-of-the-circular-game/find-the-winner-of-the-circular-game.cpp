class Solution {
public:
    int solve(vector<int>&arr,int k,int ind){
        if(arr.size() == 1){
            return arr[0];
        }
        int i = (ind + k - 1) % arr.size();
        arr.erase(arr.begin() + i);
        return solve(arr,k,i);
    }
    int findTheWinner(int n, int k) {
        vector<int>arr;
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }
        int ans = solve(arr,k,0);
        return ans;
    }
};