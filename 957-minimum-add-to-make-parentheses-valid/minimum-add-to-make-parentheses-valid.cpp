class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int insertions = 0;
        for(char ch:s){
            if(ch == '('){
                open++;
            }
            else{   // ch=')'
                if(open > 0) open--;
                else{
                    insertions++;
                }
            }
        }
        return insertions + open;
    }
};