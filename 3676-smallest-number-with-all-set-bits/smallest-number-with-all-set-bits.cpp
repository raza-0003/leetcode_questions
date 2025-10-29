class Solution {
public:
    int smallestNumber(int n) {
        int x;
        for(int i=1;i<32;i++){
            x = pow(2,i)-1;
            if(x >= n){
                return x;
            }
        }
        return x;
    }
};