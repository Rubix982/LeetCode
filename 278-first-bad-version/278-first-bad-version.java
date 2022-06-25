public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        if (n == 1) {
            return 1;
        }
        
        long start = 1;
        long end = (long)n;
        
        while (start <= end) {
            long mid = (start + end)/2;
            if (isBadVersion((int)mid)) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        return (int)start;
    }
}