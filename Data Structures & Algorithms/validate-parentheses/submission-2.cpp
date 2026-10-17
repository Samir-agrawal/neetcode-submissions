class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> mp = {{']', '['}, {')', '('}, {'}', '{'}};
        
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                // If the stack is empty OR the top doesn't match the closing bracket, it's invalid!
                if (st.empty() || st.top() != mp[c]) {
                    return false;
                }
                st.pop(); // It's a perfect match, pop it
            }
        }
        return st.empty();
    }
};
