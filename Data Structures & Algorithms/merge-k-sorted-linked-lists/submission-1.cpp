class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr;  // Start of merged list
        ListNode* n = nullptr;     // Tail pointer

        while (true) {
            int minVal = 1001;
            int minInd = -1;

            // Find the list with the smallest head value
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] && lists[i]->val < minVal) {
                    minVal = lists[i]->val;
                    minInd = i;
                }
            }

            // If no valid node is found, we're done
            if (minInd == -1) {
                return head;
            }

            // Detach the selected node from its list
            ListNode* selected = lists[minInd];
            lists[minInd] = selected->next;
            selected->next = nullptr;

            // Append to the result list
            if (!head) {
                head = selected;
                n = selected;
            } else {
                n->next = selected;
                n = n->next;
            }
        }

        return head;  // unreachable but valid fallback
    }
};
