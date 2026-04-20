class Solution {
public:
    int rev(int n){
        int revNum = 0;
        while(n){
            revNum = revNum * 10 + n % 10;
            n /= 10;
        }
        return revNum;
    }
    int mirrorDistance(int n) {
        int revNum = rev(n);
        return abs(n - revNum);
    }
};