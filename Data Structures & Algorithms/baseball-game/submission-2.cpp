class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>st;
        for(string op:operations) {
            if(st.size() && op=="C") st.pop_back();
            else if(st.size() && op=="D") st.push_back(2*st[st.size()-1]);
            else if(st.size()>1 && op=="+") {
                int first = st[st.size()-1];
                int second = st[st.size()-2];
                int newScore = first+second; 
                st.push_back(newScore);
            } else {
                st.push_back(stoi(op));
            }
        }
        int totalPoints = accumulate(st.begin(),st.end(),0);
        return totalPoints;
    }
};