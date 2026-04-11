class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int currMin = prices[0], maxPro = INT_MIN;
        for(int i=1;i<n;i++) {
            maxPro = max(maxPro, prices[i]-currMin);
            currMin = min(currMin, prices[i]);
        }
        return maxPro <= 0 ? 0 : maxPro;
    }
};
