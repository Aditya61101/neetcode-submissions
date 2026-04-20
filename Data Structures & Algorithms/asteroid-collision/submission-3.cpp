class Solution {
    bool wontCollide(int v1, int v2) {
        // if the previous asteroid is moving left or current asteroid is moving right
        // then collision is never possible
        return (v1<0 || v2>0);
    }
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int ast:asteroids) {
            if(st.empty() || wontCollide(st.top(),ast)) st.push(ast);
            else {
                while(st.size() && abs(ast) > abs(st.top()) && !wontCollide(st.top(),ast)) {
                    st.pop();
                }
                if(st.size() && abs(ast) == abs(st.top()) && !wontCollide(st.top(),ast)) st.pop();
                else if(st.empty() || wontCollide(st.top(),ast)) st.push(ast);
            }
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