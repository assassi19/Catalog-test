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
    // Test Case provided by user
    map<int, pair<int, string>> testData;

    // Adding the data from the test case
    testData[1] = {10, "28735619723837"};
    testData[2] = {16, "1A228867F0CA"};
    testData[3] = {12, "32811A4AA0B7B"};
    testData[4] = {11, "917978721331A"};
    testData[5] = {16, "1A22886782E1"};
    testData[6] = {10, "28735619654702"};
    testData[7] = {14, "71AB5070CC4B"};
    testData[8] = {9, "122662581541670"};
    testData[9] = {8, "642121030037605"};

    map<int, long long> points;

    // Decode the values based on the base
    for (const auto& data : testData) {
        int x = data.first;
        int base = data.second.first;
        string yValue = data.second.second;

        long long y = decodeValue(yValue, base);
        points[x] = y;
    }

    // Minimum number of points to interpolate (k = m + 1), given as k = 6
    int k = 6;

    // Calculate constant term (c) using Lagrange interpolation
    double constantTerm = lagrangeInterpolation(points, k);

    // Output the constant term
    cout << "Constant term (c): " << constantTerm << endl;

    return 0;
}
