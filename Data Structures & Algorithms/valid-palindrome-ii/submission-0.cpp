class Solution {
    bool ispalindrome(string s, int i, int j) {
        while(i<j) {
            if(s[i]!=s[j]) return false;
            i+=1; j-=1;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int i=0, j=n-1;
        while(i<j) {
            if(s[i]!=s[j]) {
                return ispalindrome(s,i,j-1) || ispalindrome(s,i+1,j);
            }
            i+=1; j-=1;
        }
        return true;
    }
};