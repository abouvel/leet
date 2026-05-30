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
    ListNode* reverseList(ListNode* head) {
        ListNode*copy = head;
        ListNode* prev = nullptr;
        while(head){
            copy = head->next;
            head->next = prev;
            prev = head;
            head = copy;
        }
        return prev;
    }
};
