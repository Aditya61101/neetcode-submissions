class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l=0,r=n-1;
        while(l<=r) {
            int m = l+(r-l)/2;
            if((m==0 || nums[m]<nums[m-1]) && (m==n-1 || nums[m]<nums[m+1])) {
                return nums[m];
            }
            if(nums[m]>=nums[l] && nums[m]>=nums[r]) l=m+1;
            else r=m;
        }
        return -1;
    }
};
