class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int m=l+(r-l)/2;
            // decreasing slope:
            // peak must be at m or left to it
            if(nums[m]>nums[m+1]) r=m;
            else l=m+1;
        }
        return l;
    }
};