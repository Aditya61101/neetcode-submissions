// tabulation -> bottom-up approach
class Solution {
public:
    int climbStairs(int n) {
        int one=1, two=1;
        for(int i=n-2;i>=0;i--) {
            int curr = one+two;
            two=one;
            one=curr;
        }
        return one;
    }
};
