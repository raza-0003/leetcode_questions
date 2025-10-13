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
                if(open > 0) open--; // match one '('
                else{
                    insertions++;   //Nedd one '(' before the ch=')'
                }
            }
        }
        return insertions + open;
    }
};