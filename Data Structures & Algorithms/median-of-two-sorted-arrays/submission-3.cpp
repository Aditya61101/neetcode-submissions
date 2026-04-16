// T.C: O(log(min(m,n))), S.C:O(1)
class Solution {
    double binarySearch(vector<int>&smaller, vector<int>&larger) {
        int n1 = smaller.size(), n2 = larger.size();
        int total = n1+n2, leftSize=(total+1)/2;
        int low=0, high=n1;
        double ans = 0;
        while(low<=high) {
            int cutS = low+(high-low)/2;
            int cutL = leftSize-cutS;

            int l1 = (cutS==0) ? INT_MIN : smaller[cutS-1];
            int r1 = (cutS==n1) ? INT_MAX : smaller[cutS];

            int l2 = (cutL==0) ? INT_MIN : larger[cutL-1];
            int r2 = (cutL==n2) ? INT_MAX :  larger[cutL];
            // a valid partition criteria
            if(max(l1,l2) <= min(r1,r2)) {
                // found my answer
                if(total%2==1) {
                    // [..., l1/l2][r1/r2,...]
                    ans = max(l1,l2); break;
                } else {
                    // [..., l1/l2][r1/r2,...]
                    ans = (max(l1,l2)+min(r1,r2))/2.0; break;
                }
            } else {
                // left too big, reduce smaller
                if(l1>r2) high = cutS-1;
                // left too small, increase smaller
                else if(l2>r1) low = cutS+1;
            }
        }
        return ans;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n>m) return binarySearch(nums2, nums1);
        return binarySearch(nums1, nums2);
    }
};
