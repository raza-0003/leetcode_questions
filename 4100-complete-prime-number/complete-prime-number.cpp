class Solution {
public:
    bool isPrime(int num){
        if(num <= 1) return false;
        for(int i=2;i*i<=num;i++){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }
    bool completePrime(int num) {
        int x2 = 0;
        int x1 = 0;
        int r2 = 1;
        int num2 = num;
        int r_num = 0;
        while(num2){
            int d = num2 % 10;
            r_num = r_num * 10 + d;
            num2 = num2 / 10;
        }
        while(r_num){
            int d = r_num % 10;
            x1 = x1 * 10 + d;
            if(!isPrime(x1)){
                return false;
            }
            r_num = r_num / 10;
        }
        while(num){
            int d = num % 10;
            x2 = x2 + d * r2;
            if(!isPrime(x2)){
                return false;
            }
            r2 = r2 * 10;
            num = num / 10;
        }
        return true;
    }
};