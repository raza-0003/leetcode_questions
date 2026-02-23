class Solution {
public:
    int fact(int n){
        if(n == 0 || n ==1 ){
            return 1;
        }
        return n * fact(n-1);
    }
    bool isDigitorial(int n){
        int m = n;
        int ans = 0;
        while(m){
            int digit = m % 10;
            ans += fact(digit);
            m = m/10;
        }
        return ans == n;
    }
    bool isDigitorialPermutation(int n) {
        string s = to_string(n);
        sort(s.begin(),s.end());
        do { 
            if(s[0] == '0') continue;
            int num = stoi(s);
            if(isDigitorial(num)) return true;
            
        } while (next_permutation(s.begin(), s.end()));
        return false;
        
    }
};