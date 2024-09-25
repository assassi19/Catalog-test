// Function to convert a number from a given base to base 10
function decodeValue(value, base) {
    return parseInt(value, base);
}

// Lagrange Interpolation function to find the constant term
function lagrangeInterpolation(points, k) {
    let secret = 0;
    for (let i = 0; i < k; i++) {
        let term = points[i].y; // y_i value
        for (let j = 0; j < k; j++) {
            if (i !== j) {
                term *= (0 - points[j].x) / (points[i].x - points[j].x);
            }
        }
        secret += term;
    }
    return secret;
}

// Input JSON as a string for the new test case
const jsonString = `{
    "keys": {
        "n": 9,
        "k": 6
    },
    "1": {
        "base": "10",
        "value": "28735619723837"
    },
    "2": {
        "base": "16",
        "value": "1A228867F0CA"
    },
    "3": {
        "base": "12",
        "value": "32811A4AA0B7B"
    },
    "4": {
        "base": "11",
        "value": "917978721331A"
    },
    "5": {
        "base": "16",
        "value": "1A22886782E1"
    },
    "6": {
        "base": "10",
        "value": "28735619654702"
    },
    "7": {
        "base": "14",
        "value": "71AB5070CC4B"
    },
    "8": {
        "base": "9",
        "value": "122662581541670"
    },
    "9": {
        "base": "8",
        "value": "642121030037605"
    }
}`;

// Parse the JSON input
const data = JSON.parse(jsonString);
const n = data.keys.n;
const k = data.keys.k;

// Array to store the points (x, y)
let points = [];

// Loop through the keys and decode the y values
for (let key in data) {
    if (key === "keys") continue; // Skip the "keys" object

    let x = parseInt(key); // x is the key of the object
    let base = parseInt(data[key].base); // Base of the encoded y value
    let value = data[key].value; // Encoded y value

    // Decode the y value to base 10
    let y = decodeValue(value, base);

    // Add the point (x, y) to the points array
    points.push({ x: x, y: y });
}

// Find the constant term 'c' using Lagrange interpolation
let secret = lagrangeInterpolation(points, k);

// Output the constant term
console.log("Secret (constant term 'c'):", secret);
