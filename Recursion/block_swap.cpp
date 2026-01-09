#include <iostream>
#include <vector>    // Required for std::vector
#include <algorithm> // Required for std::reverse
#include <numeric>   // Required for std::iota (optional, for easy initialization)

// Function to perform a right rotation (block swap) on a vector
void block_swap(std::vector<int> &arr, int k)
{
    int n = arr.size();
    if (n == 0 || k % n == 0)
    { // No rotation needed if empty or k is a multiple of n
        return;
    }
    k = k % n; // Normalize k to be within the bounds of the array size

    // Perform the three reversals for right rotation
    std::reverse(arr.begin(), arr.end());       // Reverse the entire array
    std::reverse(arr.begin(), arr.begin() + k); // Reverse the first k elements
    std::reverse(arr.begin() + k, arr.end());   // Reverse the remaining n-k elements
}

// Helper function to print a vector
void print_vector(const std::vector<int> &arr)
{
    for (int x : arr)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int k;

    std::cout << "Original array: ";
    print_vector(arr);

    std::cout << "Enter the number of positions to rotate (k): ";
    std::cin >> k;

    block_swap(arr, k);

    std::cout << "Array after rotation by " << k << " positions: ";
    print_vector(arr);

    return 0;
}