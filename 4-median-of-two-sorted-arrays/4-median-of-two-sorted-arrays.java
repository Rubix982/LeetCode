class Solution {
    
    private int[] answer = new int[2001];
    private int k = 0;
    
    public int[] mergeArray(int[] a, int[] b) {
        int i = 0, j = 0;
        
        while (i < a.length && j < b.length) {
            if (a[i] < b[j]) {
                answer[k] = a[i];
                i++;
            } else {
                answer[k] = b[j];
                j++;
            }
            k++;
        }

        while (i < a.length) {
            answer[k] = a[i];
            i++;
            k++;
        }

        while (j < b.length) {
            answer[k] = b[j];
            j++;
            k++;
        }

        return answer;
    }
    
    public double getMedian(int[] arr, int arrSize) {
        if (arrSize % 2 != 0) {
            return (double) arr[arrSize/2];
        } else {
            return ((double) arr[arrSize/2] + (double) arr[arrSize/2 - 1])/2;
        }    
    }
    
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1.length == 0 && nums2.length == 0) {
            return 0;
        } else if (nums1.length != 0 && nums2.length == 0) {
            return getMedian(nums1, nums1.length);
        } else if (nums1.length == 0 && nums2.length != 0) {
            return getMedian(nums2, nums2.length);
        }
        return getMedian(mergeArray(nums1, nums2), k);
    }
}