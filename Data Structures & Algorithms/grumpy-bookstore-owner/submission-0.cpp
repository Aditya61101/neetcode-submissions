class Solution {
   public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = grumpy.size(), sum = 0;
        for (int i = 0; i < n; i++) {
            // only add customers
            // when owner was not grumpy
            if (!grumpy[i]) {
                sum += customers[i];
            }
        }
        int i = 0, maxSum = 0;
        for (int j = 0; j < n; j++) {
            // only add customers
            // when owner as grumpy
            if (grumpy[j]) {
                sum += customers[j];
            }
            if (j - i + 1 > minutes) {
                if (grumpy[i]) {
                    sum -= customers[i];
                }
                i += 1;
            }
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
