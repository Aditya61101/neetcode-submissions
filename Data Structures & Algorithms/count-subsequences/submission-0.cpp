class Solution {
   public:
    int numDistinct(string s, string t) {
        int l1 = s.length();
        int l2 = t.length();

        if (l2 >= l1) return s == t;

        vector<uint> dp(l2 + 1, 0);
        dp[l2] = 1;
        for (int i = l1 - 1; i >= 0; i--) {
            // forward iteration
            // since dp[i][j] only depends on dp[i+1][j+1] i.e unupdated value at j+1
            for (int j = 0; j < l2; j++) {
                uint take = 0;
                if (s[i] == t[j]) {
                    take = dp[j + 1];
                }
                uint skip = dp[j];
                dp[j] = take + skip;
            }
        }
        return dp[0];
    }
};

