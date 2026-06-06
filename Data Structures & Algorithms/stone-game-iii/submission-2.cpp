class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>dp(4,0);

        for(int i=n-1;i>=0;i--){
            dp[i%4]=INT_MIN;
            int sum=0;
            for(int k=i;k<min(i+3,n);k++){
                sum+=stoneValue[k];
                dp[i%4]=max(dp[i%4],sum-dp[(k+1)%4]);
            }
        }
        if(dp[0]>0) return "Alice";
        return dp[0]<0 ? "Bob":"Tie";
    }
};