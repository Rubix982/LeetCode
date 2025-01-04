class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []  # Stores indices of the bars
        max_area = 0

        for i, height in enumerate(heights):
            # Pop bars when the current bar is shorter than the one at stack top
            while stack and heights[stack[-1]] > height:
                top = stack.pop()
                h = heights[top]  # Height of the popped bar
                # Width calculation
                width = i if not stack else i - stack[-1] - 1
                max_area = max(max_area, h * width)

            stack.append(i)

        # Process any remaining bars
        for i in range(len(stack)):
            h = heights[stack[i]]
            width = (len(heights) if i == 0 else len(heights) - stack[i - 1] - 1)
            max_area = max(max_area, h * width)

        return max_area
