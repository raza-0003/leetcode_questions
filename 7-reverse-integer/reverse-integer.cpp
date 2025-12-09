class Solution {
public:
    int reverse(int x) {
        bool neg = x < 0;
        if(x == INT_MIN) return 0;
        int digit = 0;
        while(x){
            int reminder = x % 10;
            if(digit > INT_MAX/10 || digit < INT_MIN/10){
                return 0;
            }
            digit = digit * 10 + reminder;
            x /= 10;
        }
        return digit;
    }
};