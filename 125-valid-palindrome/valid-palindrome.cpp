class Solution {
public:
    bool isPalindrome(string s) {
        // transforming into the lower case
        transform(s.begin(),s.end(),s.begin(),::tolower);
        // remove all special character from the string
        string result;
        for(char ch:s){
            if(isalnum(ch)){
                result += ch;
            }
        }
        int n = result.size();
        int start = 0;
        int end = n-1;
        int cnt = 0;
        bool ans = true;
        while(start < end){
            if(result[start] != result[end]){
                ans = false;
                break;
            }
            start++;
            end--;
        }
        return ans;


        
    }
};