#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getSize(ListNode* head) {
        ListNode* ptr = head;
        int sz = 0;
        while (ptr) {
            sz++;
            ptr = ptr->next;
        }
        return sz;
    }
        vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int sz = getSize(head);
        int q = sz / k, r = sz % k;
        vector<ListNode*> res;
        ListNode* ptr = head;
        while (ptr) {
            res.push_back(ptr);
            int cur_nodes;
            if (r > 0) {
                cur_nodes = q;
                r--;
            } else if (q > 0) {
                cur_nodes = q - 1;
            } else { 
                break;
            }
            while (ptr and cur_nodes--) {
                ptr = ptr->next;
            }
            if (!ptr) break;
            ListNode* temp = ptr->next;
            ptr->next = NULL;
            ptr = temp;
        }
        while (res.size() < k) {
            res.push_back(NULL);
        }
        return res;
    }
};