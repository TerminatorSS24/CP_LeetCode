/*(This problem is an interactive problem.)

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.

You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.

 

Example 1:

Input: array = [1,2,3,4,5,3,1], target = 3
Output: 2
Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.
Example 2:

Input: array = [0,1,2,4,2,1], target = 3
Output: -1
Explanation: 3 does not exist in the array, so we return -1.
**********LEETCODE POTD(12/10/2023)**********
*/
#include <iostream>
#include <vector>

using namespace std;

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class MountainArray {
public:
    int get(int index) {
        // Implementation of the get function in MountainArray
        // You can replace this with your own implementation.
        // This is just a placeholder.
        return 0;
    }

    int length() {
        // Implementation of the length function in MountainArray
        // You can replace this with your own implementation.
        // This is just a placeholder.
        return 0;
    }
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        auto peak = findPeak(mountainArr);
        auto index = binarySearch(target, mountainArr, 0, peak);
        if (index != -1) return index;
        index = binarySearchDescending(target, mountainArr, peak, mountainArr.length() - 1);
        return index;
    }

    int findPeak(MountainArray &mountainArr) {
        auto start = 0;
        auto end = mountainArr.length() - 1;
        while (start <= end) {
            auto mid = start + (end - start) / 2;
            auto m = mountainArr.get(mid);
            auto right = mountainArr.get(min(mountainArr.length() - 1, mid + 1));
            auto left = mountainArr.get(max(0, mid - 1));
            if (m >= right && m >= left) {
                return mid;
            } 
            else if (right >= m && m >= left) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return -1;
    }

    int binarySearch(int target, MountainArray &mountainArr, int start, int end) {
        while (start <= end) {
            auto mid = start + (end - start) / 2;
            if (mountainArr.get(mid) == target) return mid;
            else if (mountainArr.get(mid) > target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return -1;
    }

    int binarySearchDescending(int target, MountainArray &mountainArr, int start, int end) {
        while (start <= end) {
            auto mid = start + (end - start) / 2;
            if (mountainArr.get(mid) == target) return mid;
            else if (mountainArr.get(mid) > target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return -1;
    }
};