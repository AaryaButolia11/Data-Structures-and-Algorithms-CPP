class Solution {
public:
    // Function to calculate the maximum profit with only one transaction (buy once and sell once)
    int maxProfit(vector<int>& prices) {
        // Initialize the minimum price to the first day's price
        int bestBuy = prices[0];
        
        // Initialize max profit to 0
        int maxProfit = 0;

        // Iterate through the price list
        for(int i = 0; i < prices.size(); i++) {
            // If current price is greater than the lowest price so far,
            // check if the profit is greater than the maxProfit
            if(prices[i] > bestBuy) {
                maxProfit = max(maxProfit, prices[i] - bestBuy);
            }

            // Update the lowest price so far
            bestBuy = min(bestBuy, prices[i]);
        }

        // Return the maximum profit that could have been made
        return maxProfit;
    }
};
