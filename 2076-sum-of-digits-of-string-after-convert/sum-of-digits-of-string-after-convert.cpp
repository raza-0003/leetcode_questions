class Solution {
public:
    int getLucky(string s, int k) {
        string result;
        for(char ch:s){
            result += to_string(ch-'a'+1);
        }
        while(k--){
            int sum = 0;
            for(char digit:result){
                sum += digit-'0';
            }
            result = to_string(sum);
        }
        return stoi(result);
    }
};