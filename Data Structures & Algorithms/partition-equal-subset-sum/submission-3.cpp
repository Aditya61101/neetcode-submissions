class Solution {
    //dp[i][requiredSum] -> can we have 'requiredSum' starting from 'i'
    bool solve(int i, int target, vector<int>&nums, vector<vector<int>>&dp) {
        if(i==nums.size()) return false;
        if(target==0) return true;
        if(dp[i][target]!=-1) return dp[i][target];
        
        // for(int j=i;j<nums.size();j++){
        //     if(target < nums[j]) continue;
        //     if(solve(j+1,target-nums[j],nums,dp)) return dp[i][target]=true;
        // }
        bool take = false;
        if(target >= nums[i]) take = solve(i+1,target-nums[i],nums,dp);
        bool notTake = solve(i+1,target,nums,dp);
        
        return dp[i][target]=take || notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        // odd totalSum can never be divided into two equal halves
        if(totalSum%2 != 0) return false;

        int requiredSum = totalSum/2;
        
        vector<bool>dp(requiredSum+1,false);
        // for(int sum=0;sum<=requiredSum;sum++) if(sum==nums[n-1]) dp[sum]=true;
        
        dp[0]=true; // for i=n, we dont have any value so sum=0 is the only case in which
        // we should store true, in this case we start our loop from i=n-1 not i=n-2
        for(int i=n-1;i>=0;i--) {
            vector<bool>newDp(requiredSum+1,false);
            for(int sum=0;sum<=requiredSum;sum++) {
                bool take = false;
                if(sum >= nums[i]) take = dp[sum-nums[i]];
                bool notTake = dp[sum];
                newDp[sum] = take || notTake;
            }
            swap(dp,newDp);
        }
        return dp[requiredSum];
        // we need to find whether there's exist at least one subset 
        // whose sum is equal to requriedSum
        // vector<vector<int>>dp(n,vector<int>(requiredSum+1,-1));
        // return solve(0,requiredSum,nums,dp);
    }
};
