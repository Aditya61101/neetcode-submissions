class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if((m==0||nums[m]>nums[m-1])&&(m==n-1||nums[m]>nums[m+1])){
                return m;
            }
            if(m==0) l=m+1;
            else if(m==n-1) r=m-1;
            else if(nums[m+1]>=nums[m-1]){
                l=m+1;
            } else r=m-1;
        }
        return -1;
    }
};