class Solution {
public:
    int dfs(int amount, vector<int>& coins, int p, int sum, vector<vector<int>>& memo) {
        if (sum >= amount || p == coins.size()) return sum == amount;
        if (memo[p][sum] == -1)
            memo[p][sum] = dfs(amount, coins, p, sum + coins[p], memo) +
                              dfs(amount, coins, p + 1, sum, memo);
        return memo[p][sum];
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo(coins.size(), vector<int>(amount + 1, -1));
        return dfs(amount, coins, 0, 0, memo);
    }
};