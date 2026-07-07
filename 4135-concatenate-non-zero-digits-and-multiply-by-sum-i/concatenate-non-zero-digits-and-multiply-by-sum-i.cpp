class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        while(n){
            int d = n % 10;
            if(d != 0){
                x = x * 10 + d;
                sum += d;
            }
            n = n / 10;
        }
        long long x1 = 0;
        while(x){
            int d = x % 10;
            x1 = x1 * 10 + d;
            x = x / 10;
        }
        return 1LL*x1*sum;
        

    }
};