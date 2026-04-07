class Solution {
private:
    void solve(int start, vector<int>& nums, vector<int>& temp, vector<vector<int>>& res, int target) {
        if(target==0) {
            res.push_back(temp);
            return;
        }
        if(start==nums.size()||target<0) return;
        for(int i=start; i<nums.size();i++) {
            if(nums[i]<=target) {
                temp.push_back(nums[i]);
                solve(i, nums, temp, res, target-nums[i]);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp; vector<vector<int>>res;
        solve(0, nums, temp, res, target);
        return res;
    }
};
