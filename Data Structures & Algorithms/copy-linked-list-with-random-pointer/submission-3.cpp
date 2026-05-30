/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }
        Node* f = new Node(-1);
        Node * copy = f;
        Node * returner = f->next;
        unordered_map <Node *, Node*> u;
        while(head){
            if(!u.count(head)){
                u[head] =copy;
            }
            copy->val = head->val;
            if(u.count(head->next)){
                copy->next = u[head->next];
            }else{
                Node * next = head->next ? new Node(head->next->val) : nullptr;
                u[head->next] = next;
                copy->next = next; 
            }
            if(u.count(head->random)){
                copy->random = u[head->random];
            }else{
                Node * random = head->random ? new Node(head->random->val) : nullptr;
                u[head->random] = random;
                copy->random = random; 
            }
            copy = copy->next;
            head = head->next;
        }
        return f;
    }
};
