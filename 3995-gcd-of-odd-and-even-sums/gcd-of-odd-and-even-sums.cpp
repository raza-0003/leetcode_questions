class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd_sum = n * n;
        int even_sum = n * (n + 1);
        int large = max(odd_sum, even_sum);
        int small = min(odd_sum, even_sum);
        while(small != 0){
            int rem = large % small;
            large = small;
            small = rem;
        }
        return large;
    }
};