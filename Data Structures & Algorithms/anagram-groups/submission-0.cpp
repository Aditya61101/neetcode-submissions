class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int N = strs.size();
        vector<vector<string>>ans;
        vector<pair<string,int>>v;
        //N*K*logK
        int i=0;
        for(string str:strs){
            sort(str.begin(),str.end());
            v.push_back({str,i});
            i++;
        }
        unordered_map<string,vector<int>>ump;
        for(auto &p:v){
            ump[p.first].push_back(p.second);
        }
        for(auto &it:ump){
            vector<string>grp;
            for(int i=0;i<it.second.size();i++) grp.push_back(strs[it.second[i]]);
            ans.push_back(grp);
        }
        return ans;
    }
};
