class Solution {
    bool canHavepPairs(int m, int p, vector<int>& nums) {
        int i = 0, n = nums.size();
        while (i < n - 1) {
            if (nums[i + 1] - nums[i] <= m) {
                p -= 1;
                i += 2;
            } else
                i += 1;
            if (p == 0) return true;
        }
        return false;
    }

   public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        if (p == 0 || n < 2) return 0;
        ranges::sort(nums);
        int l = 0, r = nums[n - 1] - nums[0] + 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (canHavepPairs(m, p, nums)) {
                r = m;
            } else
                l = m + 1;
        }
        return l;
    }
};
