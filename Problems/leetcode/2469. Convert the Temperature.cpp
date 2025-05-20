class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        // Step 1: Convert Celsius to Kelvin
        // Kelvin = Celsius + 273.15
        double k = celsius + 273.15;

        // Step 2: Convert Celsius to Fahrenheit
        // Fahrenheit = Celsius × 1.80 + 32.00
        double f = celsius * 1.80 + 32.00;

        // Step 3: Create a vector to store both results
        vector<double> v;

        // Step 4: Push Kelvin and Fahrenheit values to the vector
        v.push_back(k); // First element: Kelvin
        v.push_back(f); // Second element: Fahrenheit

        // Step 5: Return the result vector
        return v;
    }
};

/*
Flow Explanation:
-----------------
Given:
    - A temperature in Celsius (e.g., 36.50)

Objective:
    - Convert it to both Kelvin and Fahrenheit
    - Return a vector containing the two converted values

Conversions:
    - Kelvin = Celsius + 273.15
    - Fahrenheit = Celsius × 1.80 + 32.00

Steps:
1. Store the Celsius value as input.
2. Use the formula to calculate the equivalent Kelvin temperature.
3. Use the formula to calculate the equivalent Fahrenheit temperature.
4. Store both values in a vector (Kelvin first, Fahrenheit second).
5. Return the vector.

Example:
---------
Input: celsius = 36.50

Kelvin = 36.50 + 273.15 = 309.65
Fahrenheit = 36.50 × 1.80 + 32.00 = 97.70

Output: [309.65, 97.70]
*/
