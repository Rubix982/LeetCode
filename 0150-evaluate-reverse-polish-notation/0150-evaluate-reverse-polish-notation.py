class Solution:

    def eval_op(self, val_one: int, val_two: int, op: str) -> int:
        if op == "+":
            return val_one + val_two
        elif op == "-":
            return val_one - val_two
        elif op == "*":
            return val_one * val_two

        result = val_one // val_two
        if val_one * val_two < 0 and val_one % val_two != 0:
            result += 1
        return result

    def evalRPN(self, tokens: List[str]) -> int:
        stack: list = []
        operators: set = {"+", "-", "*", "/"}
        val = 0

        for char in tokens:
            if char in operators:
                val_two = stack.pop()
                val = self.eval_op(stack.pop(), val_two, char)
            else:
                val = int(char)
            stack.append(val)
        
        return stack[0]