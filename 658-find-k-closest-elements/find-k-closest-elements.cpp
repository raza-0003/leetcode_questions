class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minH;
        for(int i=0;i<arr.size();i++){
            minH.push({abs(arr[i]-x),arr[i]});
        }
        while(k--){
            auto it = minH.top();
            minH.pop();
            ans.push_back(it.second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};