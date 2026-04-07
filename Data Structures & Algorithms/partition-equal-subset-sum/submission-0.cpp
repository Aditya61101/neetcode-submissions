class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2!=0) return false;
        int tar = sum/2;
        
        vector<bool>dp(tar+1, false);
        dp[0]=true;

        for(int i=n-1;i>=0;i--){
            for(int t=tar;t>=0;t--){
                bool take=false;
                if(nums[i]<=t) take = dp[t-nums[i]];
                dp[t]=take||dp[t];
            }
        }
        return dp[tar];
    }
};
