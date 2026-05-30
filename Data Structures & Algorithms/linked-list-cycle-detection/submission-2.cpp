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
    bool hasCycle(ListNode* head) {
        set<ListNode*> values;
        while(head){
            if(!values.count(head)){
                values.insert(head);
                head = head->next;
            }else{
                return true;
            }
        }
        return false;
    }
};
