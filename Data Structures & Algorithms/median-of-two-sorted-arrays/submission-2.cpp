// T.C: O(n+m), S.C:O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int total = n+m;
        // curr holds middle element whereas prev holds element just before it.
        int prev=-1, curr=-1;
        int i=0, j=0;
        // we go only till the half of the merged array
        for(int k=0;k<=total/2;k++) {
            prev = curr;
            // curr is nums1 current element if either nums2 has been exhausted or
            // nums1[i]<=nums2[j]
            if(i<n && (j>=m || nums1[i]<=nums2[j])) {
                curr = nums1[i++];
            } else {
                curr = nums2[j++];
            }
        }
        // curr -> (n+m+1)/2 (1 based)
        if(total%2==1) return curr;
        // prev -> (n+m)/2, curr -> (n+m)/2+1 (1 based)
        return (prev+curr)/2.0;
    }
};
