class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int k=0;
        int ans = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i] == '1'){
                // it is 1
                k++;
            }
            else{
                ans += k+1;
                if(k!=0) k=1;
            }
        }
        if(k > 1) ans += k+1;
        return ans;
    }
};