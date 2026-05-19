class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {

        // Initialize answer with a very large value
        // If no common element is found, we will return -1
        int common = INT_MAX;

        // Two pointers for traversing both arrays
        int i = 0;
        int j = 0;

        // Traverse both arrays until one array ends
        while (i < nums1.size() && j < nums2.size())
        {
            // If both elements are equal,
            // we found the smallest common element
            // because arrays are sorted
            if (nums1[i] == nums2[j])
            {
                common = nums1[i];
                break;
            }

            // If current element in nums1 is smaller,
            // move pointer i forward to find a bigger value
            else if (nums1[i] < nums2[j])
            {
                i++;
            }

            // Otherwise move pointer j forward
            // because nums2[j] is smaller
            else
            {
                j++;
            }
        }

        // If common element found, return it
        // otherwise return -1
        return common != INT_MAX ? common : -1;
    }
};
class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {

        // Initialize answer with a very large value
        // If no common element is found, we will return -1
        int common = INT_MAX;

        // Two pointers for traversing both arrays
        int i = 0;
        int j = 0;

        // Traverse both arrays until one array ends
        while (i < nums1.size() && j < nums2.size())
        {
            // If both elements are equal,
            // we found the smallest common element
            // because arrays are sorted
            if (nums1[i] == nums2[j])
            {
                common = nums1[i];
                break;
            }

            // If current element in nums1 is smaller,
            // move pointer i forward to find a bigger value
            else if (nums1[i] < nums2[j])
            {
                i++;
            }

            // Otherwise move pointer j forward
            // because nums2[j] is smaller
            else
            {
                j++;
            }
        }

        // If common element found, return it
        // otherwise return -1
        return common != INT_MAX ? common : -1;
    }
};