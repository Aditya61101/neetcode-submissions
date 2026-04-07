class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        stack<int>st;
        int num=0;
        char prevOp='+'; // turning the experssion from "3+2*2" to "+3+2*2"
        for(int i=0;i<=n;i++){
            if(i<n && isdigit(s[i])) {
                num=num*10+(s[i]-'0');
            } else if(i==n || s[i]!=' '){
                if(prevOp=='+') st.push(num);
                else if(prevOp=='-') st.push(-1*num);
                else if(prevOp=='*') {
                    int f=st.top(); st.pop();
                    st.push(f*num);
                } else {
                    int f=st.top(); st.pop();
                    st.push(f/num);
                }
                if(i<n) prevOp=s[i];
                num=0;
            }
        }
        // evaluating deferred expression consisting of +,-
        int ans=0;
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};