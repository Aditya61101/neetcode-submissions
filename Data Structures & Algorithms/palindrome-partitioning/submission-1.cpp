class Solution {
    vector<vector<string>>ans;
    unordered_map<string,bool>dp;
    bool palCheck(string &s) {
        int n = s.length(), i=0;
        while(i<n/2) {
            if(s[i]!=s[n-i-1]) return dp[s]=false;
            i+=1;
        }
        return dp[s]=true;
    }
    void solve(int i, string &s, vector<string>&res) {
        if(i==s.length()) ans.push_back(res);
        
        for(int j=i;j<s.length();j++) {
            string str = s.substr(i,j-i+1);
            
            bool isPal = false;
            if(dp.count(str)) isPal = dp[str];
            else isPal = palCheck(str);
            
            if(isPal) {
                res.push_back(str);
                solve(j+1,s,res);
                res.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string>res;
        solve(0,s,res);
        return ans;
    }
};
