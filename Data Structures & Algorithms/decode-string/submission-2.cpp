// T.C:O(n+N)
class Solution {
public:
    string decodeString(string s) {
        stack<string>strs;
        stack<int>freqs;
        string curr="";
        int num=0;
        for(char c:s) {
            if(c>='0' && c<='9') {
                // num=0, c='2'-> num=2; num=2, c='5' -> num=2*10+5=25
                num=num*10+c-'0';
            }
            // push current string and freq of upcoming string in stacks and start fresh
            else if(c=='[') {
                strs.push(curr);
                freqs.push(num);
                curr=""; num=0;
            }
            // pop the previous string and current string's frequency
            // multiply the current string with that frequency
            // append it with previous string
            else if(c==']') {
                int freq = freqs.top(); freqs.pop();
                string prev = strs.top(); strs.pop();
                string temp="";
                while(freq--) temp+=curr;
                curr = prev+temp;
            } else {
                curr+=c;
            }
        }
        return curr;
    }
};