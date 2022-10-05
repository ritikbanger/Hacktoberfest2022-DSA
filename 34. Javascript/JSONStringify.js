// JSON.Stringify() method converts a JavaScript object or value to a JSON string

const jsonStringify = (obj) => {
    // check if the obj is an string
    if (typeof obj === 'string') {
        return '"' + obj + '"';
    }
    // check if the obj is an number or boolean
    if (typeof obj === 'number' || typeof obj === 'boolean') {
        return obj + '';
    }

    // check if the obj is null
    if (obj === null) {
        return 'null';
    }

    // check if the obj is an array
    if (Array.isArray(obj)) {
        return '[' + obj.map(jsonStringify).join(',') + ']';
    }

    // check if the obj is an object
    if (typeof obj === 'object') {
        return '{' + Object.keys(obj).map((key) => {
            return jsonStringify(key) + ':' + jsonStringify(obj[key]);
        }).join(',') + '}';
    }
};

// Time Complextiy - O(n)
// Space Complexity - O(n)
// test cases
// console.log(jsonStringify({ a: 1, b: 2, c: 3 })); // {"a":1,"b":2,"c":3}
// console.log(jsonStringify([1, 2, 3])); // [1,2,3]