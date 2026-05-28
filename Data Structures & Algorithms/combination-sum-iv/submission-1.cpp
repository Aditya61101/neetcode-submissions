// if negative numbers are allowed in array,
// and one of our combination take that number then,
// target may never decrease to 0 hence we will have infinite recursion
// to allow negative numbers, we must impose this condition: any number can be taken
// atmost once.
class Solution {
    int solve(int target, vector<int>& nums, vector<int>&dp) {
        if(target==0) return 1;
        if(dp[target]!=-1) return dp[target];

        int count = 0;
        for(int num:nums) {
            if(num<=target) count+=solve(target-num,nums,dp);
        }
        return dp[target]=count;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,0);
        dp[0]=1; // nC0=1 i.e not selecting anything from array if target=0 and nums[i]>0
        for(int sum=1;sum<=target;sum++) {
            for(int num:nums) {
                if(num<=sum) dp[sum]+=dp[sum-num];
            }
        }
        return dp[target];
    }
};