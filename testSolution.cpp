// first iteration of the code 
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Function to convert encoded base value to decimal
long long decodeValue(const string &value, int base) {
    return stoll(value, nullptr, base);
}

// Function to perform Lagrange interpolation
double lagrangeInterpolation(const map<int, long long>& points, int k) {
    double result = 0.0;

    for (auto it1 = points.begin(); it1 != points.end(); ++it1) {
        int xi = it1->first;
        long long yi = it1->second;

        double term = yi;
        for (auto it2 = points.begin(); it2 != points.end(); ++it2) {
            if (it2->first != xi) {
                int xj = it2->first;
                term *= double(-xj) / (xi - xj);
            }
        }
        result += term;
    }

    return result;
}

int main() {
    // Sample Test Case
    map<int, pair<int, string>> testData;

    // Manual input (you can modify this part to input your own test case)
    testData[1] = {10, "4"};
    testData[2] = {2, "111"};
    testData[3] = {10, "12"};
    testData[6] = {4, "213"};

    map<int, long long> points;

    // Decode the values based on the base
    for (const auto& data : testData) {
        int x = data.first;
        int base = data.second.first;
        string yValue = data.second.second;

        long long y = decodeValue(yValue, base);
        points[x] = y;
    }

    // Minimum number of points to interpolate (k = m + 1)
    int k = 3;

    // Calculate constant term (c) using Lagrange interpolation
    double constantTerm = lagrangeInterpolation(points, k);

    // Output the constant term
    cout << "Constant term (c): " << constantTerm << endl;

    return 0;
}
