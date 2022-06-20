/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* ptr = head;
        while (ptr) {
            cnt++;
            ptr = ptr->next;
        }
        int k = cnt - n - 1;
        if (k < 0)
            return head->next;
        ptr = head;
        while (k) {
            ptr = ptr->next;
            k--;
        }
        ptr->next = ptr->next->next;
        return head;
    }
};