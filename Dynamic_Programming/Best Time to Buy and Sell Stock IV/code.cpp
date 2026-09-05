class Solution {
public:

    int f(int ind, int tranNo, vector<int>& prices, int n, int k) {

        if (ind == n || tranNo == 2 * k)
            return 0;

        if (tranNo % 2 == 0) {
            // BUY
            return max(
                -prices[ind] + f(ind + 1, tranNo + 1, prices, n, k),
                f(ind + 1, tranNo, prices, n, k)
            );
        }

        // SELL
        return max(
            prices[ind] + f(ind + 1, tranNo + 1, prices, n, k),
            f(ind + 1, tranNo, prices, n, k)
        );
    }

    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        return f(0, 0, prices, n, k);
    }
};