class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size(), n=s2.size();
        if(k>n) return false;
        
        unordered_map<char,int>freq;
        for(char s:s1) freq[s]++;
        
        int i=0;
        for(int j=0;j<n;j++) {
            // if the char present in s1 is the char present on jth index then:
            if(freq.count(s2[j])) {
                freq[s2[j]]--;
            }
            if(j-i+1>k) {
                // if the char present in s1 is the char present on ith index then:
                if(freq.count(s2[i])) freq[s2[i]]++;
                i+=1;
            }
            if(j-i+1==k) {
                bool solved = true;
                for(auto it:freq) {
                    if(it.second!=0) {solved=false; break;}
                }
                if(solved) return true;
            }
        }
        return false;

    }
};
