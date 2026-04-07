class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        int num=0, prev=0, total=0;
        char prevOp='+'; // turning the experssion from "3+2*2" to "+3+2*2"
        for(int i=0;i<=n;i++){
            if(i<n && isdigit(s[i])) {
                num=num*10+(s[i]-'0');
            } else if(i==n || s[i]!=' '){
                if(prevOp=='+') {
                    total+=prev;
                    prev=num;
                }
                else if(prevOp=='-') {
                    total+=prev;
                    prev=-1*num;
                }
                else if(prevOp=='*') {
                    prev=prev*num;
                } else {
                    prev=prev/num;
                }
                if(i<n) prevOp=s[i];
                num=0;
            }
        }
        total+=prev;
        return total;
    }
};