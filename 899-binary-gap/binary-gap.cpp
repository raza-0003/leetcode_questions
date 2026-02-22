class Solution {
public:
    int binaryGap(int n) {
        int ans = INT_MIN;
        int temp = 0;
        bool flag = false;
        while(n){
            if((n & 1) == 1){
                ans = max(ans,temp);
                temp = 1;
                flag = true;
            }
            else if((n & 1) == 0 && flag){
                temp++;
            }
            n = n/2;
        }
        return ans;
        
    }
};