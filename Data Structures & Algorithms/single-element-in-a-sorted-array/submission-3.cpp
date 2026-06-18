class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int ans = -1;
        while (l < r) {
            int m = l + (r - l) / 2;
            // if m is odd, bringing it to even index
            // to avoid complications
            // also a pair would start at even index
            if (m & 1) m--;
            // since m is even now so everything before
            // m is paired and hence if m also got its pair,
            // our single element lies to the right of m+1
            if (m < n - 1 && nums[m] == nums[m + 1]) {
                l = m + 2;
            } else {
                r = m;
            }
        }
        return nums[l];
    }
};