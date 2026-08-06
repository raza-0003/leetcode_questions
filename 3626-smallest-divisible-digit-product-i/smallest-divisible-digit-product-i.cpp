class Solution {
public:
    bool isPossible(int n, int t){
        int prod = 1;
        while(n){
            int d = n % 10;
            prod *= d;
            n = n / 10;
        }
        return prod % t == 0;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            if(isPossible(i,t)){
                return i;
            }
        }
        return -1;
    }
};