/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    return function() {
        return n++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */

// Sample Test
const n1 = 10;
const operations1 = ['call', 'call', 'call'];
const counter1 = createCounter(n1);
const output1 = operations1.map(operation => {
    return counter1();
});
console.log(output1); // [10, 11, 12]

// Sample Test
const n2 = -2;
const operations2 = ['call', 'call', 'call', 'call', 'call'];
const counter2 = createCounter(n2);
const output2 = operations2.map(operation => {
    return counter2();
});
console.log(output2); // [-2, -1, 0, 1, 2]
