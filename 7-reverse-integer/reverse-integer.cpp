#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        bool neg = x < 0;
        long long rev = x;

        string s = to_string(abs(rev));
        ::reverse(s.begin(), s.end());
        long long sum = stoll(s);
        if(neg) sum = -sum;
        if(sum > INT_MAX || sum < INT_MIN){
            return 0;
        }
        return sum;
    }
};