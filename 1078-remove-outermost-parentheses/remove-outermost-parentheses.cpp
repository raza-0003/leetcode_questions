class Solution {
public:
    string removeOuterParentheses(string s) {
        int sum = 0;
        int n = s.size();
        string ans = "";
        stack<char>st;
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch == '('){
                if(sum > 0) st.push(ch);
                sum++;
            }
            else{
                sum--;
                if(sum>0) st.push(ch);
                else{
                    string temp = "";
                    while(!st.empty()){
                        temp = st.top() + temp; /* this line is very important because of jab maine temp += st.top() it was give me wrong ans because formattiong of the ans will reverse that why we add this */
                        st.pop();
                    }
                    ans += temp;
                }
            }
        }
        return ans;
    }
};