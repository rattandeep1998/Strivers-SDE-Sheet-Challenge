#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int left = 0;
    int right = m-1;
    int top = 0;
    int bottom = n-1;

    while(left<right && top<bottom) {
        int temp = mat[top][left];
        for(int i=top; i<bottom; i++) {
            mat[i][left] = mat[i+1][left];
        }
        for(int j=left; j<right; j++) {
            mat[bottom][j] = mat[bottom][j+1];
        }
        for(int i=bottom; i>top; i--) {
            mat[i][right] = mat[i-1][right];
        }
        for (int j = right; j > left; j--) {
          mat[top][j] = mat[top][j - 1];
        }
        mat[top][left + 1] = temp;

        left++;
        right--;
        top++;
        bottom--;
    }
}