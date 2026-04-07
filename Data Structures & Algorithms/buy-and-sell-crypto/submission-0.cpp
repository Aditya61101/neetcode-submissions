class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minIdx=0, profit=0;
        for(int i=1; i<prices.size(); i++) {
            if(prices[i]>prices[minIdx]) profit=max(profit, prices[i]-prices[minIdx]);
            else minIdx=i;
        }
        return profit;
    }
};
