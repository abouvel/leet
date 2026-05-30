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
        ListNode * copy = head;
        
        int size = 0;
        while(copy){
            copy = copy->next;
            size++;
        }
        if(size ==1){
            return nullptr;
        }
        copy = head;
        int ind = size-n;
        if(ind <=0){
            return head->next;
        }
        for(int i = 0; i < size-n-1; i++){
            copy = copy->next;
        }
        copy->next = copy->next->next ? copy->next->next : nullptr;
        copy = copy->next;
        return head;
    }
};
