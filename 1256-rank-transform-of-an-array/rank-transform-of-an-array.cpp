class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>Sorted_Arr = arr;
        sort(Sorted_Arr.begin(),Sorted_Arr.end());
        unordered_map<int,int>mpp;
        int n = arr.size();
        int r = 0;
        for(int i=0;i<n;i++){
            if(mpp.find(Sorted_Arr[i]) == mpp.end()){
                r++;
                mpp[Sorted_Arr[i]] = r;
            }
            else{
                mpp[Sorted_Arr[i]] = r;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            int r = mpp[arr[i]];
            ans.push_back(r);
        }
        return ans;
    }
};