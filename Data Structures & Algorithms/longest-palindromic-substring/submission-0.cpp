class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int centers = 2*n-1;
        string ans="";
        for(int c=0;c<centers;c++){
            int left=c/2, right=left+(c%2);
            while(left>=0 && right<n && s[left]==s[right]){
                if(right-left+1>ans.size()) ans=s.substr(left, right-left+1);
                left--;
                right++;
            }
        }
        return ans;
    }
};
