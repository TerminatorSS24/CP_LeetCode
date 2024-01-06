/*
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

 

Example 1:

image: https://assets.leetcode.com/uploads/2019/10/10/sample1_1584.png

Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
Example 2:

image: https://assets.leetcode.com/uploads/2019/10/10/sample22_1584.png

Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.
Example 3:

image: https://assets.leetcode.com/uploads/2019/10/10/sample3_1584.png

Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6
**********LEETCODE POTD(05/01/2024)**********
*/
#include <stdio.h>
#include <stdlib.h>

struct list{
    int startTime;
    int endTime;
    int profit;
};

int max (int a, int b){
    return a > b ? a : b;
}

int next (int now, int finishtime, struct list* book, int startTimeSize){
    for (int i = now+1 ; i < startTimeSize ; i++){
        if (finishtime <= book[i].startTime){
            return i;
        }
    }
    return startTimeSize;
}

int comp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int jobScheduling(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int* profit, int profitSize){
    int start[50001];
    start[startTimeSize] = 0;
    struct list* book = malloc(sizeof(struct list)*startTimeSize);
    for (int i = 0 ; i < startTimeSize ; i++){
        book[i].startTime = startTime[i];
        book[i].endTime = endTime[i];
        book[i].profit = profit[i];
    } 
    qsort(book, startTimeSize, sizeof(struct list), comp);
    for (int i = startTimeSize-1 ; i >= 0 ; i--){
        start[i] = max(book[i].profit + start[next(i, book[i].endTime, book, startTimeSize)], start[i+1]);
    }
    free(book); 
    return start[0];
}