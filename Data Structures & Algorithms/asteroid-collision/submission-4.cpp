class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int ast:asteroids) {
            bool shouldInclude = true;
            while(st.size() && ast<0 && st.top()>0) {
                if(abs(ast) > abs(st.top())) {
                    st.pop();
                } else if(abs(ast)==abs(st.top())) {
                    st.pop();
                    shouldInclude = false;
                    break;
                } else {
                    shouldInclude = false;
                    break;
                }
            }
            if(shouldInclude) st.push(ast);
        }
        vector<int>state;
        while(st.size()) {
            state.push_back(st.top());
            st.pop();
        }
        reverse(state.begin(), state.end());
        return state;
    }
};