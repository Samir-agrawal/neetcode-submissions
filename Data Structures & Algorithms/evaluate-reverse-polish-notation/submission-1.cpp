class Solution {
private:
    int evaluate(char op,int operand1,int operand2)
    {
        switch(op){
            case '+': return operand1 + operand2;
            case '-': return operand1 - operand2;
            case '*': return operand1 * operand2;
            case '/': return operand1 / operand2;
            default : return 0; 
        }
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s : tokens)
        {
            int val ;
            if ( s == "+" || s == "-" || s == "*" || s == "/" )
            {
                int operand2 = st.top(); st.pop();
                int operand1 = st.top(); st.pop();
                char op = s[0];
                val = evaluate(op,operand1,operand2);
            }
            else{
                val = stoi(s);
            }
            st.push(val);
        }
        return st.top();
    }
};
