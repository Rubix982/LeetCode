class Solution {
    
    public int[] mergeArray(int[] a, int[] b) {
        int[] answer = new int[a.length + b.length];
        int i = 0, j = 0, k = 0;
        
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
    
    public double getMedian(int[] arr) {
        if (arr.length % 2 != 0) {
            return (double) arr[arr.length/2];
        } else {
            return ((double) arr[arr.length/2] + (double) arr[arr.length/2 - 1])/2;
        }    
    }
    
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        
        double total = 0.0;
        
        if (nums1.length == 0 && nums2.length == 0) {
            return 0;
        } else if (nums1.length != 0 && nums2.length == 0) {
            return getMedian(nums1);
        } else if (nums1.length == 0 && nums2.length != 0) {
            return getMedian(nums2);
        }

//         int[] arr = mergeArray(nums1, nums2);
        
//         for (int i = 0; i < arr.length ; i++) {
//             System.out.println(arr[i]);
//         }
        
        return getMedian(mergeArray(nums1, nums2));
    }
}