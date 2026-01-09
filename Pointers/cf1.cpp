#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int mex(const std::vector<int> &arr)
{
    std::set<int> s(arr.begin(), arr.end());
    int result = 0;
    while (s.count(result))
    {
        result++;
    }
    return result;
}

long long solve(std::vector<int> S)
{
    int n = S.size();
    long long total_sum = 0;
    for (int x : S)
    {
        total_sum += x;
    }

    // Count frequency of each element
    std::vector<int> count(51, 0);
    for (int x : S)
    {
        count[x]++;
    }

    long long max_score = total_sum; // Just taking sum of all elements

    // Try to get MEX = k by consuming elements 0, 1, ..., k-1
    long long consumed = 0;
    for (int k = 1; k <= 51; k++)
    {
        if (count[k - 1] > 0)
        {
            count[k - 1]--;
            consumed += (k - 1);
            long long score = k + (total_sum - consumed);
            max_score = std::max(max_score, score);
        }
        else
        {
            break;
        }
    }

    return max_score;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;
        std::vector<int> S(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> S[i];
        }

        std::cout << solve(S) << std::endl;
    }

    return 0;
}