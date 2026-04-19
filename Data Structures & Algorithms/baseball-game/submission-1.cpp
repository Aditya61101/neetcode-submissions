class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(string op:operations) {
            if(st.size() && op=="C") st.pop();
            else if(st.size() && op=="D") st.push(2*st.top());
            else if(st.size()>1 && op=="+") {
                int first = st.top(); st.pop();
                int second = st.top(); st.pop();
                int newScore = first+second;
                st.push(second); st.push(first); st.push(newScore);
            } else {
                st.push(stoi(op));
            }
        }
        int totalPoints = 0;
        while(st.size()) {
            cout<<st.top()<<" ";
            totalPoints+=st.top(); 
            st.pop();
        }
        return totalPoints;
    }
};