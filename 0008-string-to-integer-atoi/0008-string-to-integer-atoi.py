class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.strip()
        if not s:
            return 0

        s_0 = s[0]
        neg_sign = '-'
        sign = -1 if s_0 == neg_sign else 1
        if s_0 in [neg_sign, '+']:
            s = s[1:]

        result = 0
        const_decimal = 10
        for char in s:
            if not char.isdigit():
                break
            result = result * const_decimal + int(char)

        power_calc = 2 ** 31
        int_min, int_max = -power_calc, power_calc - 1
        return max(int_min, min(sign * result, int_max))
