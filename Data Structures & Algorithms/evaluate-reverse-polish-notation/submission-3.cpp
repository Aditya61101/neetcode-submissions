class Solution {
    int operate(int f, int s, char op) {
        int res;
        switch(op) {
            case '+':
                res = f+s;
                break;
            case '-':
                res = f-s;
                break;
            case '*':
                res = f*s;
                break;
            default:
                res = f/s;
        }
        return res;
    } 

public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string>operators = {"+", "-",  "*", "/"};
        stack<int>st;
        for(string token:tokens) {
            if(st.size() > 1 && operators.count(token)) {
                int second = st.top(); st.pop();
                int first = st.top(); st.pop();
                st.push(operate(first, second, token[0]));
            } else st.push(stoi(token));
        }
        return st.top();
    }
};
