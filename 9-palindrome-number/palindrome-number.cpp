class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        string str = to_string(x);
        int n = str.size();
        if(n==1) return true;
        int left = 0;
        int right = n-1;
        while(left < right){
            if(str[left] != str[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;

    }
};