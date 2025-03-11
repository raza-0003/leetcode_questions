class Solution {
public:
    int countPoints(string rings) {
        int n = rings.size();
        unordered_map<int,vector<char>>mpp;
        // for every rod mapping colour 
        for(int i=1;i<n;i+=2){
            mpp[rings[i]].push_back(rings[i-1]);
        }
        int cnt = 0;
        // checking for every rod having the coour r,g,b
        for(auto it:mpp){
            if(find(it.second.begin(),it.second.end(),'R') != it.second.end() 
             && find(it.second.begin(),it.second.end(),'G') != it.second.end()
             && find(it.second.begin(),it.second.end(),'B') != it.second.end())
             {
                // increase the count by 1
                cnt++;
            }
        }
        return cnt;
    }
};