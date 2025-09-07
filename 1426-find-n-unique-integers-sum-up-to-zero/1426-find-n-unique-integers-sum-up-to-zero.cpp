class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n);
        int index = 0;

        if (n % 2 != 0) {
            res[index++] = 0;
        }

        for (int i = 1; index < n; i++) {
            res[index++] = i;
            if (index < n) res[index++] = -i;
        }

        return res;
    }
};