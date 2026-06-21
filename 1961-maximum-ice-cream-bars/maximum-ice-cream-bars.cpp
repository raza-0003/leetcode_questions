class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(),costs.end());
        int cnt = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += costs[i];
            if(sum <= coins){
                cnt++;
            }
            else if(sum > coins){
                break;
            }
        }
        return cnt;
    }
};