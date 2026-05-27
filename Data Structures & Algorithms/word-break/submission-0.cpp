class Solution {
    int minL=INT_MAX,maxL=INT_MIN;
    unordered_set<string>wordsSet;
    int n;
    bool solve(int i, string &s, vector<int>&dp) {
        if(i==n) return true;
        if(dp[i]!=-1) return dp[i];
        
        for(int j=i+minL-1;j<min(n,i+maxL);j++) {
            if(!wordsSet.count(s.substr(i,j-i+1))) continue;

            if(solve(j+1,s,dp)) return true;
        }
        return dp[i]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        vector<int>dp(n,-1);
        for(string &w:wordDict) {
            int wl = w.length();
            minL=min(minL,wl);
            maxL=max(maxL,wl);
        }
        wordsSet.insert(wordDict.begin(),wordDict.end());
        return solve(0,s,dp);
    }
};
