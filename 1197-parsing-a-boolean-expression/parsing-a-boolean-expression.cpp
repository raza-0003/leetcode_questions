class Solution {
public:
    bool parseBoolExpr(string expression) {
        return parse(expression);
    }
    
private:
    bool parse(const string& expr) {
        // Base case: single character boolean value
        if (expr.length() == 1) {
            return expr == "t";
        }
        
        // Get the operator (first character)
        char op = expr[0];
        
        // Remove operator and outer parentheses
        string content = expr.substr(2, expr.length() - 3);
        
        // Handle NOT operator
        if (op == '!') {
            return !parse(content);
        }
        
        // Split inner expressions
        vector<string> subExprs;
        int parenCount = 0;
        string current;
        
        for (char c : content) {
            if (c == ',' && parenCount == 0) {
                subExprs.push_back(current);
                current.clear();
            } else {
                if (c == '(') parenCount++;
                if (c == ')') parenCount--;
                current += c;
            }
        }
        
        // Add last expression
        if (!current.empty()) {
            subExprs.push_back(current);
        }
        
        // Evaluate based on operator
        if (op == '&') {
            for (const string& sub : subExprs) {
                if (!parse(sub)) return false;
            }
            return true;
        } else if (op == '|') {
            for (const string& sub : subExprs) {
                if (parse(sub)) return true;
            }
            return false;
        }
        
        return false;
    }
};