class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0;
        int leftMax = 0;
        for(auto ch:s){
            if(ch == '('){
                leftMin++;
                leftMax++;
            }
            else if(ch == ')'){
                leftMin--;
                leftMax--;
            }
            else{
                leftMin--;
                leftMax++;
            }
            if(leftMax < 0){
                return false;
            }
            if(leftMin<0) leftMin = 0;

        }
        return leftMin == 0;
    }
};