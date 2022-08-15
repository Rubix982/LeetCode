class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ll = new LinkedList<>();
        int left = 0;
        int right = matrix[0].length - 1;
        int top = 0;
        int bottom = matrix.length - 1;
        while((left <= right) && (top <= bottom)){
            // Traverse upprer side  left to right.
            for(int col = left; col <= right; col++){
                ll.add(matrix[top][col]);
            }
            top++;
            // Traverse rigth side up to down
            for (int row = top; row <= bottom; row++){
                ll.add(matrix[row][right]);
            }
            right--;
            // Traverse down side rigth to left
            if (top <= bottom){
                for (int col = right; col >= left; col--){
                    ll.add(matrix[bottom][col]);
                }
            }
            bottom--;
            // Traver left side down to up
            if (left <= right){
                for (int row = bottom; row >= top; row--){
                    ll.add(matrix[row][left]);
                }
            }
            left++;
        }
        return ll;
    }
}