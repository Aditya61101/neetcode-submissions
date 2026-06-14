class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1=word1.length();
        int l2=word2.length();
        vector<int>dp(l2+1,-1);
        // base case
        for(int j=0;j<=l2;j++) dp[j]=l2-j;
        
        for(int i=l1-1;i>=0;i--){
            int prev=dp[l2];//l1-i-1
            dp[l2]=l1-i;
            for(int j=l2-1;j>=0;j--){
                int temp=dp[j];
                if(word1[i]==word2[j]){
                    dp[j]=prev;
                } else {
                    dp[j]=1+min({prev,dp[j+1],dp[j]});
                }
                prev=temp;
            }
        }
        return dp[0];
    }
};
