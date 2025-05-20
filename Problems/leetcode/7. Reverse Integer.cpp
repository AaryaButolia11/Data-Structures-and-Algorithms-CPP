class Solution
{
public:
    int reverse(int x)
    {
        int ans = 0;         // To store the reversed number
        bool isNegative = false; // Flag to remember if the input number is negative

        // Handle the edge case where x is less than INT_MIN
        // Taking -x when x == INT_MIN causes overflow since INT_MAX = 2^31 - 1 < 2^31 = -INT_MIN
        if (x <= INT_MIN)
        {
            return 0;
        }

        // If x is negative, mark it and convert x to positive
        if (x < 0)
        {
            isNegative = true;
            x = -x;
        }

        // Process each digit and build the reversed number
        while (x > 0)
        {
            // Extract the last digit
            int digit = x % 10;

            // Check for overflow: if ans * 10 will exceed INT_MAX, return 0
            // We do not check ans == INT_MAX / 10 and digit > 7 (the last digit of INT_MAX)
            // because the simpler check covers all overflow cases safely
            if (ans > INT_MAX / 10)
            {
                return 0;
            }

            // Add the digit to the reversed number
            ans = ans * 10 + digit;

            // Remove the last digit from x
            x = x / 10;
        }

        // If the original number was negative, return -ans
        return isNegative ? -ans : ans;
    }
};
