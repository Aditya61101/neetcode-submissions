class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, pair<vector<int>, bool>>mp;
        for(string &str:strs) {
            vector<int>alpha(26);
            for(char c:str) alpha[c-'a']+=1;
            mp[str] = {alpha, false};
        }

        vector<vector<string>>ans;
        for(int i=0;i<strs.size();i++) {
            // if the string is already in a anagram bucket, we skip that string
            if(mp[strs[i]].second) continue;
            mp[strs[i]].second = true;
            
            vector<string>anagrams;
            anagrams.push_back(strs[i]);

            for(int j=i+1;j<strs.size();j++) {
                // vector(26 length) comparison
                if(mp[strs[j]].first==mp[strs[i]].first) {
                    // if the frequency array are same, this means strs[i] and strs[j] are anagram
                    anagrams.push_back(strs[j]);
                    mp[strs[j]].second = true;
                }
            }
            ans.push_back(anagrams);
        }

        return ans;
    }
};
