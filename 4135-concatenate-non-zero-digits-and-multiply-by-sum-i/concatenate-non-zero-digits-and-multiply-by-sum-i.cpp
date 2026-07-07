class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        int r = 1;
        long long x = 0;
        while(n){
            int d = n % 10;
            if( d != 0){
                sum += d;
                x = r * d + x;
                r = r * 10;
            }
            n = n / 10; 
        }
        return sum * x;
    }
};