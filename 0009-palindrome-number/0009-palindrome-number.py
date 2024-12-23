class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False

        x = str(x)
        len_x = len(x)
        mid_left, mid_right = -1, -1

        if len_x % 2 == 0:
            mid_left = len_x // 2 - 1
            mid_right = len_x // 2
        else:
            mid_left = len_x // 2 - 1
            mid_right = len_x // 2 + 1

        while True:
            if mid_left < 0 or mid_right >= len_x:
                break

            if x[mid_left] != x[mid_right]:
                return False

            mid_left -= 1
            mid_right += 1

        return True
