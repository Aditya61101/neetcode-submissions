class Solution {
    int n;
    // maximum amount of money collected starting from house i
    vector<int>dp;
    int solve(int i, vector<int>&nums) {
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int choosed = nums[i]+solve(i+2,nums);
        int not_choosed = solve(i+1,nums);
        return dp[i]=max(choosed,not_choosed); 
    }
public:
    int rob(vector<int>& nums) {
        n=nums.size();
        dp.resize(n+1,-1);
        return solve(0,nums);
    }
};
