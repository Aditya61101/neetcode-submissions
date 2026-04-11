class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>freq;
        int i=0, n =s.size();
        int maxLen = 0;
        for(int j=0;j<n;j++) {
            freq[s[j]]++;
            while(i<j && freq[s[j]]>1) {
                freq[s[i]]--;
                i+=1;
            }
            maxLen = max(maxLen, j-i+1);
        }
        return maxLen;
    }
};
