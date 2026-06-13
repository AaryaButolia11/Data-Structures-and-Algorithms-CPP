class Solution
{
public:
    // by sliding window method
    int totalFruit(vector<int> &fruits)
    {
        // basket to store different kinds of fruits
        unordered_map<int, int> basket;

        int mxFruits = 0;
        int left = 0;
        // loop thru the array
        for (int right = 0; right < fruits.size(); right++)
        {
            // Include the current fruit in the basket
            basket[fruits[right]]++;
            // as only 2 distinct fruits are allowed to be kept if mroe than 2 start removing from left.
            while (basket.size() > 2)
            {
                // remove the left fruits
                basket[fruits[left]]--;
                // If count becomes zero, remove it from map
                // now if the fruit gor zero removing it
                if (basket[fruits[left]] == 0)
                {
                    basket.erase(fruits[left]);
                }
                // increment left to maintain window
                left++;
            }
            mxFruits = max(mxFruits, right - left + 1);
        }
        return mxFruits;
    }
};