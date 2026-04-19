// Valid parentheses must follow a last-opened, first-closed order — just like stacking plates.
// So we use a stack to track opening brackets.
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        unordered_map<char,char>mp;
        mp['(']=')'; mp['{']='}'; mp['[']=']';
        for(char p:s) {
            if(mp.count(p)) st.push(p);
            else if(st.size() && mp[st.top()]==p) st.pop();
            else return false;
        }
        return st.empty();
    }
};
