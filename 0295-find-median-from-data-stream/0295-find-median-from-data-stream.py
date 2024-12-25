class MedianFinder:
    def __init__(self):
        self.small = []  # Max heap (invert values to simulate max behavior)
        self.large = []  # Min heap

    def addNum(self, num: int) -> None:
        heapq.heappush(self.small, -num)  # Push to max heap
        # Balance: ensure smallest in large >= largest in small
        heapq.heappush(self.large, -heapq.heappop(self.small))

        # If odd total, balance so `small` has one extra element
        if len(self.small) < len(self.large):
            heapq.heappush(self.small, -heapq.heappop(self.large))

    def findMedian(self) -> float:
        if len(self.small) > len(self.large):  # Odd total
            return -self.small[0]
        return (-self.small[0] + self.large[0]) / 2  # Even total
