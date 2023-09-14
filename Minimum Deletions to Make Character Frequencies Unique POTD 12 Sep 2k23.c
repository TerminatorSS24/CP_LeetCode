/*A string s is called good if there are no two different characters in s that have the same frequency.

Given a string s, return the minimum number of characters you need to delete to make s good.

The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

 

Example 1:

Input: s = "aab"
Output: 0
Explanation: s is already good.
Example 2:

Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".
Example 3:

Input: s = "ceabaacb"
Output: 2
Explanation: You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).
**********LEETCODE POTD(12/09/2023)**********
*/
static int cmp_int_desc(const int * const pCur, const int * const pBase){
	return -(*pCur - *pBase);
}

int minDeletions(const char * const str){
	int lowerCnts[26];
	memset( &lowerCnts, 0, sizeof (lowerCnts) );
	for (int i = 0; str[i] != '\0'; i += 1){
		assert(str[i] >= 'a' && str[i] <= 'z');
		lowerCnts[ str[i] - 'a' ] += 1;
	}

	qsort(lowerCnts, 26, sizeof (int), &cmp_int_desc);

	int delCnt = 0;

	for (int i = 1; i < 26; i += 1){
		if (0 == lowerCnts[i]){
			break;
		}

		if (lowerCnts[i] == lowerCnts[i - 1]){
			int equalCnt = 1;
			while (
				i + equalCnt < 26 &&
				lowerCnts[i + equalCnt] == lowerCnts[i]
			){
				equalCnt += 1;
			}

			delCnt += equalCnt;
			for (int j = 0; j < equalCnt; j += 1){
				lowerCnts[i + j] -= 1;
			}
		}
	}

	return delCnt;
}