// Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Implement KthLargest class:

// KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
// int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.

// Example 1:

// Input
// ["KthLargest", "add", "add", "add", "add", "add"]
// [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
// Output
// [null, 4, 5, 5, 8, 8]

// Explanation
// KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
// kthLargest.add(3);   // return 4
// kthLargest.add(5);   // return 5
// kthLargest.add(10);  // return 5
// kthLargest.add(9);   // return 8
// kthLargest.add(4);   // return 8

#include <stdlib.h>

typedef struct
{
    int *heap;
    int size;
    int k;
} KthLargest;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int *heap, int size, int index)
{
    int parent = (index - 1) / 2;
    while (index > 0 && heap[parent] > heap[index])
    {
        swap(&heap[parent], &heap[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void heapifyDown(int *heap, int size, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index)
    {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

KthLargest *kthLargestCreate(int k, int *nums, int numsSize)
{
    KthLargest *obj = (KthLargest *)malloc(sizeof(KthLargest));
    obj->heap = (int *)malloc(k * sizeof(int));
    obj->size = 0;
    obj->k = k;

    for (int i = 0; i < numsSize && i < k; i++)
    {
        obj->heap[obj->size++] = nums[i];
        heapifyUp(obj->heap, obj->size, obj->size - 1);
    }

    for (int i = k; i < numsSize; i++)
    {
        if (nums[i] > obj->heap[0])
        {
            obj->heap[0] = nums[i];
            heapifyDown(obj->heap, obj->size, 0);
        }
    }

    return obj;
}

int kthLargestAdd(KthLargest *obj, int val)
{
    if (obj->size < obj->k)
    {
        obj->heap[obj->size++] = val;
        heapifyUp(obj->heap, obj->size, obj->size - 1);
    }
    else if (val > obj->heap[0])
    {
        obj->heap[0] = val;
        heapifyDown(obj->heap, obj->size, 0);
    }

    return obj->heap[0];
}

void kthLargestFree(KthLargest *obj)
{
    free(obj->heap);
    free(obj);
}
