class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int sign = 1;
        int i = 0;
        long ans = 0;
        // step1 skip the leading white space
        while(i<n && s[i] == ' '){
            i++;
        }
        // step-2 handle the sign 
        if( i<n && (s[i] == '+' || s[i] == '-')){
            sign = (s[i]=='-')? -1 :1;
            i++;
        }
        // step 03 convert number while handling overflow
        while(i<n && isdigit(s[i])){
            ans = ans * 10 + (s[i]-'0');
            // handling the edge cases and overflow cases
            if(ans * sign > INT_MAX) return INT_MAX;
            if(ans * sign < INT_MIN) return INT_MIN;
            i++;
        }
        return ans * sign;
    }
};