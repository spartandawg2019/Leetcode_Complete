class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int hold = -prices[0];
        int sold = 0, rest = 0;
        for (int i = 1; i < n; i++) {
            int prev = sold;
            sold = max(sold, hold + prices[i]);
            hold = max(hold, rest - prices[i]);
            rest = max(rest, prev);
        }
        return max(sold, rest);
    }
};
