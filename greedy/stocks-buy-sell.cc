class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, n = prices.size();
        int profit = 0;
        while(i < n - 1){
            if(prices[i] <= prices[i + 1])
                profit += (prices[i + 1] - prices[i]);
            i++;
        }
        return profit;
    }
};