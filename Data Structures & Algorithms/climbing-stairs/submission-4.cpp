// tabulation -> bottom-up approach
class Solution {
public:
    int climbStairs(int n) {
        int curr=1, p_n_1=1, p_n_2=1;
        for(int i=n-2;i>=0;i--) {
            curr = p_n_1+p_n_2;
            p_n_2=p_n_1;
            p_n_1=curr;
        }
        return curr;
    }
};
