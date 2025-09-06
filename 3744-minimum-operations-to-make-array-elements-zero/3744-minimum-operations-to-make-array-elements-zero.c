#define MAX_POW 16
long long pow4_table[MAX_POW];  // 4^0 ... 4^15

// Precompute once at program start
void init_pow4_table() {
    pow4_table[0] = 1;
    for (int i = 1; i < MAX_POW; i++) {
        pow4_table[i] = pow4_table[i-1] * 4;
    }
}

long long steps_to_zero_sum(int start, int end) {
    long long sum = 0;

    for (int i = 0; i < MAX_POW; i++) {
        long long block_start = pow4_table[i];
        long long block_end   = pow4_table[i] * 4 - 1;

        long long l = start > block_start ? start : block_start;
        long long r = end   < block_end   ? end   : block_end;

        if (l <= r) sum += (r - l + 1) * (i + 1);
        if (block_start > end) break;
    }

    return (sum + 1)/2;
}

long long minOperations(int** queries, int queriesSize, int* queriesColSize) {
    init_pow4_table();

    int i = 0;
    long long total_ops = 0;
    for (i = 0; i < queriesSize; i++) {
        total_ops += steps_to_zero_sum(queries[i][0], queries[i][1]);
    }
    return total_ops;
}