class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        // kitna petrol kam
        int deficit = 0;
        // kitna petrol extra
        int balance = 0;
        // circuit start point
        int start = 0;

        // check for all petrol pumps
        for (int i = 0; i < gas.size(); i++)
        {
            // balance is the addition of gas at curr petrol pump minus the cost to old petrol pump
            balance += gas[i] - cost[i];
            // if balance is less than zero ie. no fuel left or dist to be travlled is greater than fuel curr
            if (balance < 0)
            {
                // inc deficit of fuel
                deficit += balance;
                // check for next node
                start = i + 1;
                // new balance to be zero
                balance = 0;
            }
        }
        // if we have more fuel than dist to be travlled return start idx
        if (balance + deficit >= 0)
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
};