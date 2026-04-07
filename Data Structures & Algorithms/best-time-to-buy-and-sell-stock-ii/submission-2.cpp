class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int curBuy=0, curSell=0, nextBuy=0,nextSell=0;
        // 0 -> buy, 1 -> sell
        for(int i=n-1;i>=0;i--) {
            curBuy = max(-1*prices[i]+nextSell,nextBuy);
            curSell = max(prices[i]+nextBuy,nextSell);

            nextBuy=curBuy;
            nextSell=curSell;
        }
        return curBuy;
    }
};