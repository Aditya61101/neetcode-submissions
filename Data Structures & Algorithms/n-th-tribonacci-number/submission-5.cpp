class Solution {
    // tabulation: top-bottom, space optimized
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        int p1=0,p2=1,p3=1;
        for(int i=3;i<=n;i++) {
            int curr=p1+p2+p3;
            p1=p2;
            p2=p3;
            p3=curr;
        }
        return p3;
    }
};