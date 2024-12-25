class MedianFinder:
    def __init__(self):
        self.small = []  # Max heap (invert values to simulate max behavior)
        self.large = []  # Min heap

    def addNum(self, num: int) -> None:
        # Inline push and pop operations
        if not self.small or num <= -self.small[0]:
            heapq.heappush(self.small, -num)
        else:
            heapq.heappush(self.large, num)

        # Balance heaps (small can have at most one more element than large)
        if len(self.small) > len(self.large) + 1:
            heapq.heappush(self.large, -heapq.heappop(self.small))
        elif len(self.large) > len(self.small):
            heapq.heappush(self.small, -heapq.heappop(self.large))

    def findMedian(self) -> float:
        if len(self.small) > len(self.large):  # Odd total
            return -self.small[0]
        return (-self.small[0] + self.large[0]) / 2  # Even total
