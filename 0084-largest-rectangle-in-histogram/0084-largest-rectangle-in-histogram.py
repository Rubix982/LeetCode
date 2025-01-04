class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []  # Stores indices of the bars
        max_area = 0
        n = len(heights)

        for i, height in enumerate(heights):
            # Pop bars when the current bar is shorter than the one at stack top
            while stack and heights[stack[-1]] > height:
                h = heights[stack.pop()]  # Height of the popped bar
                width = i if not stack else i - stack[-1] - 1
                max_area = max(max_area, h * width)

            stack.append(i)

        # Process any remaining bars
        for idx, elem in enumerate(stack):
            max_area = max(max_area, heights[elem] * (n if idx == 0 else n - stack[idx - 1] - 1))
        
        return max_area
