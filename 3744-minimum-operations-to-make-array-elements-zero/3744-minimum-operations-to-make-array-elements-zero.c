#include <stdio.h>
#include <math.h>

const double LOG4 = log(4);

long long steps_to_zero_sum(int start, int end) {
    long long sum = 0;
    long long pow4 = 1;   // current block start: 4^0 = 1
    long long step = 1;   // numbers in this block take 'step' operations

    while (pow4 <= end) {
        long long block_start = pow4;
        long long block_end   = pow4 * 4 - 1;

        // Find intersection with [start, end]
        long long l = start > block_start ? start : block_start;
        long long r = end   < block_end   ? end   : block_end;

        if (l <= r) {
            sum += (r - l + 1) * step;  // all numbers in this intersection take 'step' operations
        }

        // Move to the next block
        if (pow4 > 1073741823) break;  // prevent overflow (4^15 > 10^9)
        pow4 *= 4;
        step++;
    }

    return sum;
}

long long minOperations(int** queries, int queriesSize, int* queriesColSize) {
    int i = 0;
    long long total_ops = 0;
    for (i = 0; i < queriesSize; i++) {
        total_ops += (steps_to_zero_sum(queries[i][0], queries[i][1]) + 1) / 2;
    }
    return total_ops;
}