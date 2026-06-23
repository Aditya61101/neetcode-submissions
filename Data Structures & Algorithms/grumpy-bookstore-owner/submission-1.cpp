class Solution {
   public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = grumpy.size();

        int i = 0, maxSum = 0;
        int sum = 0, satisfied = 0;
        for (int j = 0; j < n; j++) {
            // only add customers
            // when owner as grumpy
            if (grumpy[j]) {
                sum += customers[j];
            } else {
                satisfied += customers[j];
            }
            if (j - i + 1 > minutes) {
                if (grumpy[i]) {
                    sum -= customers[i];
                }
                i += 1;
            }
            maxSum = max(maxSum, sum);
        }
        return maxSum + satisfied;
    }
};
