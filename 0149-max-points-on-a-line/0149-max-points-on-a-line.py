class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        if len(points) <= 2:
            return len(points)

        max_points_on_a_line = 1

        for i in range(len(points)):
            slopes = defaultdict(int)
            duplicates = 1
            current_max = 0

            for j in range(len(points)):
                if i == j:
                    continue

                if points[i] == points[j]:
                    duplicates += 1
                else:
                    x1, y1 = points[i]
                    x2, y2 = points[j]
                    dy, dx = y2 - y1, x2 - x1
                    gcd = self.__gcd(dx, dy)
                    dx //= gcd
                    dy //= gcd
                    slopes[(dx, dy)] += 1
                    current_max = max(current_max, slopes[(dx, dy)])

            max_points_on_a_line = max(max_points_on_a_line, current_max + duplicates)

        return max_points_on_a_line

    def __gcd(self, a: int, b: int) -> int:
        while b:
            a, b = b, a % b
        return abs(a)
