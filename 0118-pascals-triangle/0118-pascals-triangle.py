class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        results = []
        for i in range(numRows):
            if i == 0:
                results.append([1]) # [[1]]
                continue

            if i == 1:
                results.append([1, 1]) # [[1], [1, 1]]
                continue

            last_level = results[-1]
            level_results = [1]
            for j in range(len(last_level)):
                if j + 1 != len(last_level):
                    level_results.append(last_level[j] + last_level[j+1])

            level_results.append(1)
            results.append(level_results)

        return results
