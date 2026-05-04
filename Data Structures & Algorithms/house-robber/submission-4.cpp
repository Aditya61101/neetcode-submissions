class Solution {
    int n;
    // maximum amount of money collected starting from house i
    vector<int>dp;
public:
    int rob(vector<int>& nums) {
        n=nums.size();
        dp.resize(n+1,-1);
        dp[n]=0;
        dp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) {
            dp[i]=max(dp[i+1],nums[i]+dp[i+2]);
        }
        return dp[0];
    }
};
