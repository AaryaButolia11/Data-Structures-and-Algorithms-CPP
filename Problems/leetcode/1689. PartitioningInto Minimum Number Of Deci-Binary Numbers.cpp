class Solution
{
public:
    int minPartitions(string n)
    {
        char maxCh = *max_element(begin(n), end(n));
        return maxCh - '0';
    }
};

// ex 32
// 3->2->1->0
// 2->1->0

// so as 3 is greater we needed 3 operations for 3 so ans -> 3