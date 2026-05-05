#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void findMaxProfit(vector<int> &prices, int i, int &minprice, int &profit)
{
    // Base case
    if (i >= prices.size())
        return;

    if (prices[i] < minprice)
    {
        minprice = prices[i];
    }

    if (prices[i] - minprice > profit)
    {
        profit = prices[i] - minprice;
    }

    findMaxProfit(prices, i + 1, minprice, profit);
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int minPrice = INT_MAX;
    int profit = 0;

    findMaxProfit(prices, 0, minPrice, profit);

    cout << profit << endl;

    return 0;
}