class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) == 1:
            return False

        stack: list = []
        for idx, val in enumerate(s):
            if val in ['(', '[', '{']:
                stack.append(val)
            elif val in [')', ']', '}']:
                if len(stack) == 0:
                    return False
                stack_val = stack[-1]
                if stack_val == '(' and val != ')':
                    return False
                elif stack_val == '[' and val != ']':
                    return False
                elif stack_val == '{' and val != '}':
                    return False
                stack.pop(len(stack) - 1)
        
        return len(stack) == 0
        