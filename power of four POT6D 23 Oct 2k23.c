/*Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.


Example 1:

Input: n = 16
Output: true
Example 2:

Input: n = 5
Output: false
Example 3:

Input: n = 1
Output: true
**********LEETCODE POTD(23/10/2023)**********
*/
#include<stdbool.h>
bool isPowerOfFour(const int num){
	return (
		num >= 1 &&
		( num & (num - 1) ) == 0 &&
		(num - 1) % 3 == 0
	);
}