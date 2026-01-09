#include <vector>
#include <numeric>   // Required for std::accumulate
#include <algorithm> // Required for std::max (though not explicitly used in your provided code, good to include for general array operations)

using namespace std;

class Solution
{
public:
    // This function checks if it's possible to allocate books such that no student
    // gets more than 'mid' pages.
    bool isPossibleSolution(int A[], int N, int M, int mid)
    {
        int pageSum = 0; // Current sum of pages for the current student
        int c = 1;       // Number of students required

        for (int i = 0; i < N; i++)
        {
            // If the current book's pages alone exceed the 'mid' value,
            // it's impossible to allocate, as even one student cannot take this book.
            if (A[i] > mid)
            {
                return false;
            }

            // If adding this book to the current student's pages exceeds 'mid',
            // assign this book to a new student.
            if (pageSum + A[i] > mid)
            {
                c++;            // Increment student count
                pageSum = A[i]; // Start a new sum for the new student with the current book

                // If the number of students required 'c' exceeds the available students 'M',
                // it's not possible to allocate.
                if (c > M)
                {
                    return false;
                }
            }
            else
            {
                // Add current book's pages to the current student's sum
                pageSum += A[i];
            }
        }
        // If we successfully allocated all books within the 'mid' limit
        // and with 'M' or fewer students, then it's a possible solution.
        return true;
    }

    // This function finds the minimum possible value for the maximum number of pages
    // assigned to any student.
    int findPages(int A[], int N, int M)
    {
        // Edge case: If there are more students than books, or no books,
        // allocation is not possible as each student must get at least one book.
        if (M > N || N == 0)
        {
            return -1;
        }

        int start = 0;                     // The minimum possible value for the maximum pages (could be 0, or the largest single book)
        int end = accumulate(A, A + N, 0); // The maximum possible value for the maximum pages (sum of all pages)
        int ans = -1;                      // To store the best possible answer found

        // Perform binary search on the possible range of the maximum pages
        while (start <= end)
        {
            int mid = start + (end - start) / 2; // Calculate the midpoint to avoid potential overflow

            // Check if it's possible to allocate books such that no student
            // gets more than 'mid' pages.
            if (isPossibleSolution(A, N, M, mid))
            {
                // If 'mid' is a possible solution, it means we can potentially
                // do even better (find a smaller maximum). So, store 'mid' as a
                // potential answer and try searching in the lower half.
                ans = mid;
                end = mid - 1;
            }
            else
            {
                // If 'mid' is not a possible solution, it means 'mid' is too small.
                // We need to increase the minimum pages per student, so search in the upper half.
                start = mid + 1;
            }
        }
        // Return the minimum maximum pages found that satisfies the conditions.
        return ans;
    }
};