class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(auto &w : words)
            freq[w]++;
        vector<pair<string,int>> arr(freq.begin(), freq.end());
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            if(a.second == b.second)
                return a.first < b.first;   // lexicographically smaller first
            return a.second > b.second;     // higher frequency first
        });
        vector<string> ans;
        for(int i = 0; i < k; i++)
            ans.push_back(arr[i].first);
        return ans;
    }
};