class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        for(string &str:strs) {
            vector<int>alpha(26);
            for(char c:str) alpha[c-'a']+=1;
            
            string key="#";
            for(int i=0;i<26;i++) {
                key+=to_string(alpha[i]);
                key+='#';
            }
            mp[key].push_back(str);
        }

        vector<vector<string>>ans;
        for(auto &it:mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
