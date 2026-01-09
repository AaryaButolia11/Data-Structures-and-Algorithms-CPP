#include <vector>
#include <numeric>
#include <algorithm> // Required for std::max

class Solution
{
public:
    // Helper function to check if a given 'maxPagesPerStudent' is a possible solution
    // A: Array of book pages
    // N: Number of books
    // M: Number of students
    // maxPagesPerStudent: The maximum pages a single student is allowed to read
    bool isPossibleSolution(const std::vector<int> &A, int N, int M, int maxPagesPerStudent)
    {
        int studentsCount = 1;        // Start with the first student
        long long currentPageSum = 0; // Use long long to avoid overflow for large page sums

        for (int i = 0; i < N; i++)
        {
            // If any book has more pages than the allowed maximum, it's not possible
            if (A[i] > maxPagesPerStudent)
            {
                return false;
            }

            // If adding the current book exceeds the allowed maximum for the current student
            if (currentPageSum + A[i] > maxPagesPerStudent)
            {
                studentsCount++;       // Assign this book to the next student
                currentPageSum = A[i]; // Start new sum for the next student with current book
                // If we need more students than available, this 'maxPagesPerStudent' is not possible
                if (studentsCount > M)
                {
                    return false;
                }
            }
            else
            {
                // Otherwise, add the current book to the current student's sum
                currentPageSum += A[i];
            }
        }
        return true; // All books can be distributed with the given 'maxPagesPerStudent'
    }

    // Function to find the minimum number of pages
    // arr: Vector of book pages
    // k: Number of students
    int findPages(std::vector<int> &arr, int k)
    {
        int N = arr.size(); // Number of books
        int M = k;          // Number of students

        // Edge case: If there are more students than books, it's not possible to assign one book per student.
        // Or if there are no books, return -1.
        if (M > N || N == 0)
        {
            return -1;
        }

        // The search space for the answer (minimum max pages) will be:
        // 'start': Minimum possible pages any student has to read is the maximum pages of a single book.
        //          (Because at least one student will read the largest book).
        // 'end': Maximum possible pages any student has to read is the total sum of all pages.
        //        (This happens if only one student reads all books).
        int start = 0;
        int end = 0;
        for (int pages : arr)
        {
            start = std::max(start, pages); // Minimum possible answer is the max pages in a single book
            end += pages;                   // Maximum possible answer is the sum of all pages
        }

        int ans = -1; // Stores the minimum possible maximum pages

        // Binary search for the optimal solution
        while (start <= end)
        {
            int mid = start + (end - start) / 2; // Avoids potential overflow compared to (start+end)/2

            if (isPossibleSolution(arr, N, M, mid))
            {
                // If 'mid' is a possible solution, it means we *can* achieve this
                // maximum. We try to find an even smaller maximum.
                ans = mid;
                end = mid - 1; // Try searching in the lower half
            }
            else
            {
                // If 'mid' is not a possible solution, it means 'mid' is too small
                // (some student has to read more than 'mid' pages).
                // We need to increase the allowed maximum.
                start = mid + 1; // Try searching in the upper half
            }
        }
        return ans;
    }
};