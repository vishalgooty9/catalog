#include <iostream>
#include <map>
#include <string>
#include <cstdlib>  // for strtol
#include <cmath>

// Function to convert a string representing a number in a given base to base-10 (integer)
int base_to_decimal(const std::string& value, int base) {
    return std::strtol(value.c_str(), nullptr, base);  // Convert a string from any base to decimal
}

// Function to calculate the constant term (c) from the roots
double calculate_constant_term(const std::map<std::string, std::pair<std::string, std::string>>& roots, int n) {
    double constant_term = 1.0;

    // Iterate over the map of roots
    for (const auto& root_pair : roots) {
        const std::string& base_str = root_pair.second.first;  // Get base as string
        const std::string& value_str = root_pair.second.second;  // Get value as string

        // Convert the base from string to integer
        int base = base_to_decimal(base_str, 10);  // Base is in base 10, convert to int

        // Convert the value from its given base to decimal
        int root_value = base_to_decimal(value_str, base);  // Convert root value to base-10

        constant_term *= -root_value;  // Multiply by the negative root value
    }

    return constant_term;
}

int main() {
    // Define the map for the polynomial roots with keys as strings
    std::map<std::string, std::pair<std::string, std::string>> roots;

    // Manually insert the roots into the map with their base and value
    roots["1"] = {"10", "4"};
    roots["2"] = {"2", "111"};
    roots["3"] = {"10", "12"};
    roots["6"] = {"4", "213"};

    // Define n and k
    int n = 4;  // Number of roots provided
    int k = 3;  // Minimum number of roots required (k = m + 1)

    // Check if there are enough roots provided
    if (n < k) {
        std::cout << "Error: Not enough roots provided. Needed at least " << k << " roots but only " << n << " provided.\n";
        return 1;
    }

    // Calculate the constant term
    double constant_term = calculate_constant_term(roots, n);

    // Output the constant term
    std::cout << "The constant term (c) of the polynomial is: " << constant_term << std::endl;

    return 0;
}
