class Solution:

    def eval_op(self, val_one: int, val_two: int, op: str) -> int:
        if op == "+":
            return val_one + val_two
        elif op == "-":
            return val_one - val_two
        elif op == "*":
            return val_one * val_two

        if val_one * val_two < 0 and val_one % val_two != 0:
            return val_one // val_two + 1
        return val_one // val_two

    def evalRPN(self, tokens: List[str]) -> int:

        if len(tokens) == 0:
            return 0

        if len(tokens) == 1:
            return int(tokens[0])

        if len(tokens) == 2:
            return int(token[0]) + int(token[1])

        if len(tokens) == 3:
            return self.eval_op(int(tokens[0]), int(tokens[1]), tokens[2])

        stack: list = []

        for idx, char in enumerate(tokens):
            if char not in ["+", "-", "*", "/"]:
                stack.append(int(char))
            else:
                val_two = int(stack.pop())
                val_one = int(stack.pop())
                stack.append(self.eval_op(val_one, val_two, char))
        
        return stack[0]
