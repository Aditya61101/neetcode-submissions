class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tsz = nums1.size();
        int z = tsz-1;
        int i=m-1, j=n-1;

        while(i>=0 && j>=0) {
            if(nums1[i]>=nums2[j]) {
                nums1[z]=nums1[i];
                i-=1;
            } else {
                nums1[z]=nums2[j];
                j-=1;
            }
            z-=1;
        }
        while(j>=0){
            nums1[z--]=nums2[j--];
        }
    }
};