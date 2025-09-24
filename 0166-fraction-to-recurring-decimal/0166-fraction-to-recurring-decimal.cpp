class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result;

        // handle sign
        if ((numerator < 0) ^ (denominator < 0)) result += "-";

        // convert to long long to avoid overflow
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        // integer part
        result += to_string(n / d);
        long long remainder = n % d;
        if (remainder == 0) return result;  // no fractional part

        result += ".";

        unordered_map<long long, int> remainderIndex;
        while (remainder != 0) {
            if (remainderIndex.count(remainder)) {
                // cycle detected
                result.insert(remainderIndex[remainder], "(");
                result += ")";
                break;
            }
            remainderIndex[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / d);
            remainder %= d;
        }

        return result;
    }
};
