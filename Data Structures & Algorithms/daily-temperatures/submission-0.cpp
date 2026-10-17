class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> countHotterDay(n,0);
        vector<int> nextHotterIdx(n,-1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            
            if (!st.empty()) {
                countHotterDay[i] = st.top() - i; 
            }
            
            st.push(i);
        }
        
        return countHotterDay;
    }
};
