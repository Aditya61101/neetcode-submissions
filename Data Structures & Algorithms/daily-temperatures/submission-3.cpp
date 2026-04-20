class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int n = temperatures.size();
        vector<int>result(n);
        // strictly decreasing order(bottom to top)
        for(int i=n-1;i>=0;i--) {
            while(st.size() && temperatures[i]>=temperatures[st.top()]) st.pop();
            if(st.size()) result[i] = st.top()-i;
            st.push(i);
        }
        return result;
    }
};
