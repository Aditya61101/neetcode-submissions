class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>dp(n+1,0);

        for(int i=n-1;i>=0;i--){
            dp[i]=INT_MIN;
            int sum=0;
            for(int k=i;k<min(i+3,n);k++){
                sum+=stoneValue[k];
                dp[i]=max(dp[i],sum-dp[k+1]);
            }
        }
        if(dp[0]>0) return "Alice";
        return dp[0]<0 ? "Bob":"Tie";
    }
};