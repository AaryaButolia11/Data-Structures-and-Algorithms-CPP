class Solution
{
public:
    // tc -> O(logn)(2n) (1n for whole merging left side and 1n for including right side ele only once!!)
    // sc -> O(n)
    long long cnt = 0;

    void merge(vector<int> &arr, vector<int> &temp,
               int start, int mid, int end)
    {
        int i = start, j = mid + 1, k = start;

        while (i <= mid && j <= end)
        {
            if (arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }

        while (i <= mid)
            temp[k++] = arr[i++];

        while (j <= end)
            temp[k++] = arr[j++];

        for (int idx = start; idx <= end; idx++)
            arr[idx] = temp[idx];
    }

    void countPairs(vector<int> &arr,
                    int start, int mid, int end)
    {
        int j = mid + 1;

        for (int i = start; i <= mid; i++)
        {
            while (j <= end &&
                   (long long)arr[i] > 2LL * arr[j])
            {
                j++;
            }

            cnt += j - (mid + 1);
        }
    }

    void mergeSort(vector<int> &arr,
                   vector<int> &temp,
                   int start, int end)
    {
        if (start >= end)
            return;

        int mid = start + (end - start) / 2;

        mergeSort(arr, temp, start, mid);
        mergeSort(arr, temp, mid + 1, end);

        countPairs(arr, start, mid, end);

        merge(arr, temp, start, mid, end);
    }

    int reversePairs(vector<int> &nums)
    {

        vector<int> temp(nums.size(), 0);

        mergeSort(nums, temp, 0, nums.size() - 1);

        return cnt;
    }
};