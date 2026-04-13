#define ll long long
class Solution {
public:
    int mySqrt(int x) {
        int l=1, r=x+1;
        while(l<r) {
            int m = l+(r-l)/2;
            if((ll)m*(ll)m>=(ll)x) r=m;
            else l=m+1;
        }
        return (ll)l*(ll)l==(ll)x ? l:l-1;
    }
};