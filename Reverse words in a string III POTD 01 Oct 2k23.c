/*Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "God Ding"
Output: "doG gniD"
**********LEETCODE POTD(01/10/2023)**********
*/
static void reverse_chs(char *const chs, const int chsLen)
{
    for (int left = 0, right = chsLen - 1; left < right; left += 1, right -= 1)
    {
        const char buf = chs[left];
        chs[left] = chs[right];
        chs[right] = buf;
    }
}
char *reverseWords(char *const str)
{
    for (char *word = str; 1;)
    {
        assert(*word != '\0' && *word != ' ');
        int wordLen = 1;
        while (word[wordLen] != '\0' && word[wordLen] != ' ')
        {
            wordLen += 1;
        }
        reverse_chs(word, wordLen);
        if ('\0' == word[wordLen])
            break;
        word += wordLen + 1;
    }
    return str;
}