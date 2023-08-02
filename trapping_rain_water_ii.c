// Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.
// Example 1:

// image : https://assets.leetcode.com/uploads/2021/04/08/trap1-3d.jpg

// Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
// Output: 4
// Explanation: After the rain, water is trapped between the blocks.
// We have two small ponds 1 and 3 units trapped.
// The total volume of water trapped is 4.

// Example 2:

//image: https://assets.leetcode.com/uploads/2021/04/08/trap2-3d.jpg

// Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
// Output: 10
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int height;
} Cell;

// Function to compare cells based on their heights for the priority queue
int compare(const void* a, const void* b) {
    return ((Cell*)a)->height - ((Cell*)b)->height;
}

// Check if the cell is valid (within the grid boundaries)
bool isValidCell(int row, int col, int numRows, int numCols) {
    return row >= 0 && row < numRows && col >= 0 && col < numCols;
}

int trapRainWater(int** heightMap, int heightMapSize, int* heightMapColSize) {
    if (heightMap == NULL || heightMapSize <= 2 || heightMapColSize == NULL || *heightMapColSize <= 2) {
        return 0;
    }

    int numRows = heightMapSize;
    int numCols = *heightMapColSize;

    
    Cell* heap = (Cell*)malloc(numRows * numCols * sizeof(Cell));
    int heapSize = 0;

    bool** visited = (bool**)malloc(numRows * sizeof(bool*));
    for (int i = 0; i < numRows; i++) {
        visited[i] = (bool*)calloc(numCols, sizeof(bool));
    }

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (i == 0 || i == numRows - 1 || j == 0 || j == numCols - 1) {
                heap[heapSize].row = i;
                heap[heapSize].col = j;
                heap[heapSize].height = heightMap[i][j];
                heapSize++;
                visited[i][j] = true;
            }
        }
    }

    int trappedWater = 0;
    int maxBoundaryHeight = 0;

    qsort(heap, heapSize, sizeof(Cell), compare);

    while (heapSize > 0) {
        Cell currentCell = heap[0];
        heap[0] = heap[heapSize - 1];
        heapSize--;

        int idx = 0;
        while (true) {
            int leftChildIdx = 2 * idx + 1;
            int rightChildIdx = 2 * idx + 2;
            int smallestChildIdx = idx;

            if (leftChildIdx < heapSize && heap[leftChildIdx].height < heap[smallestChildIdx].height) {
                smallestChildIdx = leftChildIdx;
            }

            if (rightChildIdx < heapSize && heap[rightChildIdx].height < heap[smallestChildIdx].height) {
                smallestChildIdx = rightChildIdx;
            }

            if (smallestChildIdx == idx) {
                break;
            }

            Cell temp = heap[idx];
            heap[idx] = heap[smallestChildIdx];
            heap[smallestChildIdx] = temp;

            idx = smallestChildIdx;
        }

        maxBoundaryHeight = maxBoundaryHeight > currentCell.height ? maxBoundaryHeight : currentCell.height;

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; i++) {
            int newRow = currentCell.row + directions[i][0];
            int newCol = currentCell.col + directions[i][1];

            if (isValidCell(newRow, newCol, numRows, numCols) && !visited[newRow][newCol]) {
                visited[newRow][newCol] = true;
                int newHeight = heightMap[newRow][newCol];

                if (newHeight < maxBoundaryHeight) {
                    trappedWater += maxBoundaryHeight - newHeight;
                }

                heap[heapSize].row = newRow;
                heap[heapSize].col = newCol;
                heap[heapSize].height = newHeight;
                heapSize++;

                int childIdx = heapSize - 1;
                int parentIdx = (childIdx - 1) / 2;
                while (childIdx > 0 && heap[parentIdx].height > heap[childIdx].height) {
                    Cell temp = heap[parentIdx];
                    heap[parentIdx] = heap[childIdx];
                    heap[childIdx] = temp;

                    childIdx = parentIdx;
                    parentIdx = (childIdx - 1) / 2;
                }
            }
        }
    }

    free(heap);
    for (int i = 0; i < numRows; i++) {
        free(visited[i]);
    }
    free(visited);

    return trappedWater;
}
