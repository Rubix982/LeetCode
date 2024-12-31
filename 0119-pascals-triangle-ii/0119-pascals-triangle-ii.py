class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        results = [[1]]
        for i in range(1, rowIndex + 1):
            prev = results[-1]
            results.append([1] + [prev[j] + prev[j + 1] for j in range(len(prev) - 1)] + [1])

        return results[-1]
