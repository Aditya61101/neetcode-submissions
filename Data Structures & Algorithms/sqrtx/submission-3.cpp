#define ll long long
class Solution {
public:
    int mySqrt(int x) {
        int l=0, r=x;
        while(l<r) {
            int m = l+(r-l)/2;
            // the squares of integers are monotonically increasing
            if((ll)m*(ll)m>=(ll)x) r=m;
            else l=m+1;
        }
        // if l*l==x then l is the exact sq. root 
        // else l is the first number whose square is greater than x, hence we return l-1
        return (ll)l*(ll)l==(ll)x ? l:l-1;
    }
};