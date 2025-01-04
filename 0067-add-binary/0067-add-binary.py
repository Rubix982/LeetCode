class Solution:
    def addBinary(self, a: str, b: str) -> str:
        max_len = max(len(a), len(b))
        result = []
        a, b = a.zfill(max_len), b.zfill(max_len)
        carry = 0

        for i in range(max_len - 1, -1, -1):
            total = carry + int(a[i]) + int(b[i])
            result.append(str(total % 2))
            carry = total // 2

        if carry:
            result.append("1")

        return ''.join(result[::-1])
