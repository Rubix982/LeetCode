class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix or not matrix[0]:
            return 0

        rows, cols = len(matrix), len(matrix[0])
        heights = [0] * cols
        max_size = 0

        def largestRectangleArea(heights):
            stack = []
            max_area = 0
            heights.append(0)  # Add a sentinel to ensure we process all columns

            for i, h in enumerate(heights):
                while stack and heights[stack[-1]] > h:
                    height = heights[stack.pop()]
                    width = i if not stack else i - stack[-1] - 1
                    max_area = max(max_area, height * width)
                stack.append(i)

            heights.pop()  # Remove the sentinel
            return max_area

        for row in matrix:
            for col in range(cols):
                heights[col] = heights[col] + 1 if row[col] == '1' else 0
            # Calculate the largest rectangle for the updated histogram
            max_size = max(max_size, largestRectangleArea(heights))

        return max_size
