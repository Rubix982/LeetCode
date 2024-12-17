class Solution:
    def romanToInt(self, s: str) -> int:
        if not s:
            return 0

        roman_to_val = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }

        if len(s) == 1:
            return roman_to_val[s[0]]

        roman_sum: int = 0
        prev_val: int = 0

        for char in reversed(s):
            curr_val = roman_to_val[char]
            mutliplier = -1 if curr_val < prev_val else 1
            curr_val = curr_val * mutliplier
            roman_sum = roman_sum + curr_val
            prev_val = curr_val

        return roman_sum
