// Flatten an array of arrays
// Input: [1, 2, [3, 4, [5, 6, [7, 8, [9, 10]]]]], 4
// Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]


const flattenArray = (arr, depth = 1) => {
    return arr.reduce((a, v) => a.concat(depth > 1 && Array.isArray(v) ? flattenArray(v, depth - 1) : v),[]);
};

// Time Complexity - O(n)
// Space Complexity - O(n)
// Test Cases:
// console.log(flattenArray([1, 2, [3, 4, [5, 6, [7, 8, [9, 10]]]]], 4));
// console.log(flattenArray([1, 2, [3, 4, [5, 6, [7, 8, [9, 10]]]]], 3));