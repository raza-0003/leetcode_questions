class Solution {
public:
    void evaluate(stack<char>&optr,stack<char>&operand){
        char op = optr.top();
        optr.pop();
        bool ans;
        if(op == '|'){
            ans = false;
            while(operand.top() != '('){
                ans |= (operand.top() == 't');
                operand.pop();
            }
            operand.pop();  // pop the '('
        }
        else if(op == '&'){
            ans = true;
            while(operand.top() != '('){
                ans &= (operand.top() == 't');
                operand.pop();
            }
            operand.pop();  // pop the '('
        }
        else if(op == '!'){
            ans = (operand.top() == 't');
            ans = !ans;
            operand.pop(); // pop  the value;
            operand.pop();  // pop the '('
        }
        if(ans) operand.push('t');
        else{
            operand.push('f');
        }
    }

    bool parseBoolExpr(string expression ) {
        stack<char> optr,operand;
        int ind = 0;
        while(expression[ind]){
            if(expression[ind] == '!' || expression[ind] == '&' || expression[ind] == '|'){
                optr.push(expression[ind]);
            }
            else if(expression[ind] == 't' || expression[ind] == 'f' ){
                operand.push(expression[ind]);
            }
            else if(expression[ind] == '(' ){
                operand.push(expression[ind]);
            }
            else if(expression[ind] == ')' ){
                evaluate(optr,operand);
            }
            ind++;
        }
        return operand.top() == 't';
    }
};