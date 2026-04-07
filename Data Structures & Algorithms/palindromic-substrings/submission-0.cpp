class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            // odd length, one center
            int l=i, r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                count++;
                l--; r++;
            }
            // even length, two centers
            l=i, r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                count++;
                l--; r++;
            }
        }
        return count;
    }
};
