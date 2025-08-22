class Solution {
public:

    int f(vector<int>& prices, int index, int buy, vector<vector<int>>& dp,int fee) {
        if (index >= prices.size()) return 0;

        if (dp[index][buy] != -1) return dp[index][buy];

        if (buy == 1) {
            // Choice: Buy or Skip
            return dp[index][buy] = max(-prices[index] + f(prices, index + 1, 0, dp,fee),
                                        f(prices, index + 1, 1, dp,fee));
        } else {
            // Choice: Sell (then cooldown → index+2) or Skip
            return dp[index][buy] = max(prices[index] -fee+ f(prices, index + 1, 1, dp,fee),
                                        f(prices, index + 1, 0, dp,fee));
        }
    }







    int maxProfit(vector<int>& prices, int fee) {
                int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(prices, 0, 1, dp,fee); // start with index 0, allowed to buy
    }
};