class Solution {
public:
    const int MOD = 1000000007;
    // 1E9 MEANS 1 KE BAAD 9 DIGIT 
    long long mode_exp(long long base,long long exp,long long mod){
        long long result = 1;
        while(exp>0){
            if(exp%2 == 1){
                // if odd multiply the base
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp = exp / 2;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long odd_ind = n /2 ;
        long long  even_ind = n /2 + n % 2;
        long long ans = (mode_exp(5,even_ind,MOD) % MOD);
        ans = (ans * (mode_exp(4,odd_ind,MOD) % MOD)) % MOD;
        return int(ans);
    }
};