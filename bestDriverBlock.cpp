1
function selectBestDriverBlock(groupSize, availability) {
    const n = availability.length;
    if (groupSize === 0 || n === 0) return 0;

    let dq = []; // will store indices
    let result = 0;

    for (let i = 0; i < n; i++) {
        // Remove indices that are out of this window
        while (dq.length > 0 && dq[0] <= i - groupSize) {
            dq.shift();
        }

        // Maintain deque in increasing order of values
        while (dq.length > 0 && availability[dq[dq.length - 1]] >= availability[i]) {
            dq.pop();
        }

        dq.push(i);

        // When we reach window size, record the min
        if (i >= groupSize - 1) {
            let windowMin = availability[dq[0]];
            result = Math.max(result, windowMin);
        }
    }

    return result;
}

// Example usage:
let availability = [12, 7, 9, 15, 6, 10, 8];
let groupSize = 3;
console.log(selectBestDriverBlock(groupSize, availability)); 
// Expected Output: 7
