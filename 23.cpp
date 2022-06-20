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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                        greater<pair<int, ListNode*>>> pq;
        ListNode* head = new ListNode(9999);
        ListNode* ptr = head;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i])
                pq.push({lists[i]->val, lists[i]});
        }
        while (!pq.empty()) {
            auto [val, node] = pq.top();
            pq.pop();
            if (node->next) {
                pq.push({node->next->val, node->next});
            }
            ptr->next = node;
            ptr = ptr->next;
        }
        return head->next;
    }
};