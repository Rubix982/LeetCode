class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        len_points = len(points)
        if len_points <= 2:
            return len_points

        ans = 0
        slopes = defaultdict(int)

        for i in range(len_points):
            slopes.clear()            
            x1, y1 = points[i]

            for j in range(i + 1, len_points):
                x2, y2 = points[j]
                slope = math.inf if x2 - x1 == 0 else (y2 - y1) / (x2 - x1)
                slopes[slope] += 1
                ans = max(ans, slopes[slope])
 
        return ans + 1
