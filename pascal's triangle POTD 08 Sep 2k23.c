/*Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

image: https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif
 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
**********LEETCODE POTD(08/09/2023)**********
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnSize=numRows;
     int **pascal=(int **)malloc(sizeof(int*)*numRows);
     *returnColumnSizes=malloc(sizeof(int)*numRows);
     for(int i=0;i<numRows;i++)
     {
         (*returnColumnSizes)[i]=i+1;
         pascal[i]=(int*)malloc(sizeof(int)*(*returnColumnSizes)[i]);
         for(int j=0;j<=i;j++)
         {
             if(j==0||j==i)
              pascal[i][j]=1;
             else
              pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
         }
     }
     return pascal;
}