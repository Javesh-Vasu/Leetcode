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
    ListNode* r;
    ListNode* reverseList(ListNode* head) {
        if ( !head || !head->next ) return head; 
        ListNode* newhead = reverse(head,head->next);
        newhead->next = nullptr;
        return r;
    }
    
    ListNode* reverse(ListNode* head, ListNode* headNext){
        if(headNext == nullptr) {
            r = head;
            return head;
        }
        ListNode* Node = reverse(headNext,headNext->next);
        Node->next = head;
        return head;
    }
};