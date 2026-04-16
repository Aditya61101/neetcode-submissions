/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l=0, r=n-1;
        // peak element
        while(l<r) {
            int m = l+(r-l)/2;
            if(mountainArr.get(m) > mountainArr.get(m+1)) r=m;
            else l=m+1;
        }
        int peak = l;
        // peak element is at l
        if(mountainArr.get(peak)==target) return peak;
        // find in left part
        l=0, r=peak-1;
        while(l<r) {
            int m = l+(r-l)/2;
            if(mountainArr.get(m)>=target) r=m;
            else l=m+1;
        }
        if(mountainArr.get(l)==target) return l;
        // find in right part
        l=peak+1, r=n-1;
        while(l<r) {
            int m = l+(r-l)/2;
            if(mountainArr.get(m)<=target) r=m;
            else l=m+1;
        }
        if(mountainArr.get(l)==target) return l;
        return -1;
    }
};