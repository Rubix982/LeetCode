class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) == 1:
            return False

        bracket_map = {')': '(', ']': '[', '}': '{'}
        bracket_map_values = bracket_map.values()
        stack = []

        for char in s:
            if char in bracket_map_values:
                stack.append(char)
            elif char in bracket_map:
                if not stack or stack[-1] != bracket_map[char]:
                    return False
                stack.pop()

        return not stack
        