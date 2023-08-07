class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m=matrix.length,n=matrix[0].length;
        int i=m-1,j=0;
        while(i>=0 && j<=n-1){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]<target) j++;
            else i--;
        }
        return false;
    }
}