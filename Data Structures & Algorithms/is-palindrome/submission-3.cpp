class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int i=0, j=n-1;
        while(i<j) {
            while(i<j && !isalnum(s[i])) i+=1;
            while(i<j && !isalnum(s[j])) j-=1;
            if(i>=j) break;
            if(tolower(s[i])!=tolower(s[j])) return false;

            i+=1;
            j-=1;
        }
        return true;
    }
};
