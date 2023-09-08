/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.*/
#include<stdio.h>
#include<stdbool.h>

bool contains(int *nums, int numsSize, int val)
{
    int i;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] == val)
        {
            return true;
        }
    }
    return false;
}

bool visit(int **mat,int matSize, int idx, int *hist,int histSize,int** nums){

/*Base case 1, index is already visited,return 1 if it is safe, 0 if it is not safe*/


    if (nums[idx][0])
    {
        if (nums[idx][1])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

/*Base case 2, hist is an array of ints, that records the index visited. If the actual index (here called idx) is already in hist, this means there is a loop, so it is not safe*/


    if(contains(hist,histSize,idx)==true){
        nums[idx][0] = 1;
        nums[idx][2] = 1;
        return false;
    }
    
/*We record the index in history*/

    hist[histSize]=idx;
    histSize++;
    int i;

    for(i=0;i<matSize;i++){

/*If there is a conenction, analyze it*/

        if(mat[idx][i]){

/*If the return of the recursive is 0, this means it has a loop, so we return 0 and update the actual index*/

            if(visit(mat,matSize,i,hist,histSize,nums)==false){
                nums[idx][0] = 1;
                nums[idx][2] = 1;
                return false;
            }
        }
    }

/*If we end the loop, the node is safe, update and return 1*/

    nums[idx][0] = 1;
    nums[idx][1] = 1;
    return true;
}

bool canFinish(int numCourses, int **prerequisites, int prerequisitesSize, int *prerequisitesColSize)
{
    if(numCourses==1||!prerequisitesSize||prerequisitesSize==1){
    return true;
}
    int **mat = (int **)malloc(sizeof(int*) * numCourses), i;
    int **nums = (int **)calloc(numCourses, sizeof(int *));
    int *hist = (int *)malloc(sizeof(int) * numCourses);


    for (i = 0; i < numCourses; i++)
    {   
        nums[i] = (int *)calloc(3, sizeof(int));
        mat[i]=(int*)calloc(numCourses,sizeof(int));
    }

/*Initialise the matrix with the connections*/

    for(i=0;i<prerequisitesSize;i++){
        mat[prerequisites[i][1]][prerequisites[i][0]]=1;
    }

    for(i = 0; i < numCourses; i++){

        /*If nums[i][0]==0, means it is not visited so we visit it*/

        if(!nums[i][0]){
            if(visit(mat,numCourses,i,hist,0,nums)==false)
            {
                free(hist);
                for (i = 0; i < numCourses; i++)
                {   
                    free(mat[i]);
                    free(nums[i]);
                }
                free(mat);
                free(nums);
                return false;
            }
        }
    }

    free(hist);
    for (i = 0; i < numCourses; i++)
        {   
            free(mat[i]);
            free(nums[i]);
        }
    free(mat);
    free(nums);
    return true;
}