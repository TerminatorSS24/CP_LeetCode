/*You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

 

Example 1:

Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
Output: [2,0,3]
Explanation: 
The number of soldiers in each row is: 
- Row 0: 2 
- Row 1: 4 
- Row 2: 1 
- Row 3: 2 
- Row 4: 5 
The rows ordered from weakest to strongest are [2,0,3,1,4].
Example 2:

Input: mat = 
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]], 
k = 2
Output: [0,2]
Explanation: 
The number of soldiers in each row is: 
- Row 0: 1 
- Row 1: 4 
- Row 2: 1 
- Row 3: 1 
The rows ordered from weakest to strongest are [0,2,3,1].
**********LEETCODE POTD(18/09/2023)**********
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef bool (*HCmpFn)(const void *a, const void *b);

typedef struct Heap {
    void *data;
    int len;
    int cap;
    int elem_size;
    void *swap_space;
    HCmpFn less;
} Heap;

void hInit(Heap *h, int elem_size, HCmpFn fn) {
    h->cap = 8;
    h->len = 0;
    h->less = fn;
    h->elem_size = elem_size;
    h->swap_space = calloc(elem_size, 1);
    h->data = calloc(h->cap, elem_size);
}

inline void *hElemAt(Heap *h, int index) {
    return (void*)((uint8_t*)h->data + index * h->elem_size);
}

void hFree(Heap *h) {
    h->cap = 0;
    h->len = 0;
    if (h->data) {
        free(h->data);
        free(h->swap_space);
        h->data = 0;
        h->swap_space = 0;
    }
}

void hSwap(Heap *h, int i, int j) {
    memmove(h->swap_space, hElemAt(h, i), h->elem_size);
    memmove(hElemAt(h, i), hElemAt(h, j), h->elem_size);
    memmove(hElemAt(h, j), h->swap_space, h->elem_size);
}

void hSiftDown(Heap *h, int index) {
    int left, right, curr = index;
    while (curr < h->len) {
        index = curr;
        left = 2*(curr+1)-1;
        right = left+1;
        if (left < h->len && h->less(hElemAt(h, left), hElemAt(h, curr))) {
            curr = left;
        }
        if (right < h->len && h->less(hElemAt(h, right), hElemAt(h, curr))) {
            curr = right;
        }
        if (curr == index) {
            break;
        }
        hSwap(h, index, curr);
    }
}

void hSiftUp(Heap *h, int index) {
    int parent;
    while (index > 0) {
        parent = (index+1)/2 - 1;
        if (!h->less(hElemAt(h, index), hElemAt(h, parent))) {
            break;
        }
        hSwap(h, index, parent);
        index = parent;
    }
}

bool hPeek(Heap *h, void *e) {
    if (!h->len) {
        return false;
    }
    memmove(e, hElemAt(h, 0), h->elem_size);
    return true;
}

bool hPop(Heap *h, void *e) {
    if (!h->len) {
        return false;
    }
    memmove(e, hElemAt(h, 0), h->elem_size);
    memmove(hElemAt(h, 0), hElemAt(h, h->len-1), h->elem_size);
    h->len--;
    hSiftDown(h, 0);
    return true;
}

void hGrow(Heap *h, int need) {
    need += h->len;
    int cap = h->cap;
    if (cap < need) {
        cap *= 2;
    }
    if (cap == h->cap) {
        return;
    }
    void *p = calloc(cap, h->elem_size);
    memmove(p, h->data, h->len * h->elem_size);
    free(h->data);
    h->data = p;
    h->cap = cap;
}

void hPush(Heap *h, void *e) {
    hGrow(h, 1);
    memmove(hElemAt(h, h->len++), e, h->elem_size);
    hSiftUp(h, h->len-1);
}

typedef struct State {
    int index;
    int nSoldiers;
} State;

bool cmpFn(const void *a, const void *b) {
    const State *s1 = (const State *)a, *s2 = (const State*)b;
    return s1->nSoldiers < s2->nSoldiers ||
        s1->nSoldiers == s2->nSoldiers && s1->index < s2->index;
}

static void printState(const void *s) {
    const State *s1 = s;
    printf("State {index: %d, nSoldiers: %d}", s1->index, s1->nSoldiers);
}

int countSoldiers(int *arr, int len) {
    int lo = 0, hi = len-1;
    while (lo < hi) {
        int m = lo + (hi-lo)/2;
        if (arr[m] > 0) {
            lo = m+1;
        } else {
            hi = m;
        }
    }
    return arr[lo] == 0 ? lo : len;
}

static void hDump(Heap *h, void (*printElem)(const void *e)) {
    bool hasEol = false;
    puts("--- BEGIN HEAP DUMP ---");
    for (int i = 1; i <= h->len; i++) {
        if (i > 1 && !(i & i-1)) {
            putchar(10);
            hasEol = true;
        } else {
            hasEol = false;
        }
        printElem(hElemAt(h, i-1));
        printf(" :: ");
    }
    if (!hasEol) putchar(10);
    puts("--- END HEAP DUMP ---");
}

int* kWeakestRows(int** mat, int rows, int* pCols, int k, int* rSize){
    Heap h;
    State t;
    hInit(&h, sizeof t, cmpFn);
    for (int i = 0; i < rows; i++) {
        t.index = i;
        t.nSoldiers = countSoldiers(mat[i], *pCols);
        hPush(&h, &t);
    }
    *rSize = k;
    int *ans = calloc(k, sizeof *ans);
    for (int i = 0; i < k; i++) {
        hPop(&h, &t);
        ans[i] = t.index;
    }
    hFree(&h);
    return ans;
}