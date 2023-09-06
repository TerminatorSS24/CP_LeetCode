/*Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.

 

Example 1:


Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].
Example 2:


Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
**********LEETCODE POTD(06/09/2023)**********
*/
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        vector<ListNode*> temp;

        if (head == nullptr) {
            while (k--) {
                ans.push_back(nullptr);
            }
            return ans;
        }

        ListNode *ptr = head;
        int cnt = 0;

        while (ptr != nullptr) {
            cnt++;
            temp.push_back(ptr);
            ptr = ptr->next;
        }

        if (cnt < k) {
            ptr = head;
            while (ptr != nullptr) {
                ListNode *copy = new ListNode(ptr->val);
                copy->next = nullptr;
                ans.push_back(copy);
                ptr = ptr->next;
                k--;
            }
            while (k--) {
                ans.push_back(nullptr);
            }
            return ans;
        }

        int bundle = (cnt / k);
        int extra = cnt % k;
        ptr = head;
        while (ptr != nullptr) {
            int comb = bundle;
            if (extra) {
                comb++;
                extra--;

                ListNode *h = new ListNode(-1);
                ListNode *ptr2 = h;

                while (comb--) {
                    ListNode *copy = new ListNode(ptr->val);
                    copy->next = nullptr;

                    ptr2->next = copy;

                    ptr2 = ptr2->next;
                    ptr = ptr->next;
                }
                ans.push_back(h->next);
            }
            else {
                ListNode *h = new ListNode(-1);
                ListNode *ptr2 = h;

                while (comb--) {
                    ListNode *copy = new ListNode(ptr->val);
                    copy->next = nullptr;
                    ptr2->next = copy;
                    ptr2 = ptr2->next;
                    ptr = ptr->next;
                }
                ans.push_back(h->next);
            }
        }

        return ans;
    }
};
