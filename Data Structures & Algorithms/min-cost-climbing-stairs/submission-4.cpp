class Solution {
    // space optimized represents min cost to reach n starting from i
    // T.C: O(n), S.C: O(1)
    int n;
public:
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        int top = 0, second_last=cost[n-1];
        for(int i=n-2;i>=0;i--) {
            int curr=cost[i]+min(top,second_last);
            top=second_last;
            second_last=curr;
        }
        
        return min(top,second_last);
    }
};
