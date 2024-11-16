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
        if ( head == nullptr ) return head;
        map<Node*,Node*> originalToCopy;
        Node* newHead = new Node(head->val);
        Node* copy_temp = newHead;
        Node* orig_temp = head->next;
        originalToCopy[head] = newHead;
        while( orig_temp ){
            Node* nh = new Node(orig_temp->val);
            copy_temp->next = nh;
            copy_temp = nh;
            originalToCopy[orig_temp] = nh; 
            orig_temp = orig_temp->next;
        }
        
        Node* temp = head;
        Node* temp2 = newHead;
        
        while(temp){
            Node* rand = temp->random;
            Node* randforcopy = originalToCopy[rand];
            temp2->random = randforcopy;
            temp = temp->next;
            temp2 = temp2->next;
        }
        return newHead;
    }
};