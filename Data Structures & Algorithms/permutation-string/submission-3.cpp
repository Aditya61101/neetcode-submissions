class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size(), n=s2.size();
        if(k>n) return false;
        
        vector<int>freq(26);
        for(char s:s1) freq[s-'a']++;
        int required = k;
        int i=0;
        for(int j=0;j<n;j++) {
            if(freq[s2[j]-'a']>0) {
                required--;
            }
            freq[s2[j]-'a']--;
            if(j-i+1>k) {
                if(freq[s2[i]-'a']>=0) required++;
                freq[s2[i]-'a']++;
                i+=1;
            }
            if(required==0) return true;
        }
        return false;

    }
};
