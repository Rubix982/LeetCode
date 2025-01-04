class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a_len, b_len = len(a), len(b)
        max_len = max(a_len, b_len)
        result = ["0"] * max_len

        if a_len < b_len:
            a = ("0" * (b_len - a_len)) + a
        elif b_len < a_len:
            b = ("0" * (a_len - b_len)) + b

        print(a, b)
        # For the case that both the lengths are equal
        i = max_len - 1
        carry = 0
        while i >= 0:
            if a[i] == "0" and b[i] == "0": # Both are zeroes
                if carry == 1:
                    result[i] = "1"
                    carry = 0
                else:
                    result[i] = "0"
            elif a[i] == "0" or b[i] == "0": # There is at least one zero and one "one"
                if carry == 1:
                    result[i] = "0"
                    # we will not update the carry here
                else:
                    result[i] = "1"
            elif a[i] == "1" and b[i] == "1": # Both are ones
                if carry == 1:
                    result[i] = "1"
                    # we will not update carry here
                else:
                    result[i] = "0"
                    carry = 1

            i -=1

        if carry == 1:
            # if result[0] == "1":
            #    result[0] = "0"
            result = ["1"] + result

        return ''.join(result)
