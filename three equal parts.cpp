// You are given an array arr which consists of only zeros and ones, divide the array into three non-empty parts such that all of these parts represent the same binary value.

// If it is possible, return any [i, j] with i + 1 < j, such that:

// arr[0], arr[1], ..., arr[i] is the first part,
// arr[i + 1], arr[i + 2], ..., arr[j - 1] is the second part, and
// arr[j], arr[j + 1], ..., arr[arr.length - 1] is the third part.
// All three parts have equal binary values.
// If it is not possible, return [-1, -1].

// Note that the entire part is used when considering what binary value it represents. For example, [1,1,0] represents 6 in decimal, not 3. Also, leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.

 

// Example 1:

// Input: arr = [1,0,1,0,1]
// Output: [0,3]
// Example 2:

// Input: arr = [1,1,0,1,1]
// Output: [-1,-1]
// Example 3:

// Input: arr = [1,1,0,0,1]
// Output: [0,2]
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int countOnes = 0;
        for(int& i : arr){
            if(i == 1) countOnes++;
        }
        if(countOnes % 3 != 0) return {-1, -1};
        if(countOnes == 0) return{0, (int)arr.size() - 1};
        countOnes /= 3;

        int lastPartStart = arr.size() - 1, currOnes = 0;
        while(lastPartStart >= 0 && currOnes < countOnes){
            if(arr[lastPartStart] == 1){
                currOnes++;
            }
            lastPartStart--;
        }
        
        int firstPartEnd = 0;
        while(arr[firstPartEnd] == 0) firstPartEnd++;
        for(int r = lastPartStart + 1; r < arr.size(); firstPartEnd++, r++){
            if(arr[firstPartEnd] != arr[r]) return {-1, -1};
        }
        firstPartEnd--;

        int lastIndexStart = firstPartEnd + 1;
        while(arr[lastIndexStart] == 0) lastIndexStart++;
        for(int r = lastPartStart + 1; r < arr.size(); lastIndexStart++, r++){
            if(arr[lastIndexStart] != arr[r]) return {-1, -1};
        }

        return {firstPartEnd, lastIndexStart};
    }
};