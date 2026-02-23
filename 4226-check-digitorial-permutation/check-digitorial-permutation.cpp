class Solution {
public:
    int fact(int n){
        if(n == 1 || n == 0){
            return 1;
        }
        return n * fact(n-1);
    }
     bool isPermutation(int a, int b) {
        int freq[10] = {0};
        while (a > 0) {
            freq[a % 10]++;
            a /= 10;
        }
        while (b > 0) {
            freq[b % 10]--;
            b /= 10;
        }
        for (int i = 0; i < 10; i++) {
            if (freq[i] != 0) return false;
        }
        return true;
    }
    bool isDigitorialPermutation(int n) {
        int mpp[10];
        mpp[0] = 1;
        mpp[1] = 1;
        for(int i=2;i<=9;i++){
            mpp[i] = fact(i);
        }
        int m = n;
        int ans = 0;
        while(m){
            int digit = m % 10;
            ans += mpp[digit];
            m = m/10;
        }
        return isPermutation(ans,n);
        
    }
};