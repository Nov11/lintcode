/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr){return;}
        ListNode node(0);
        node.next = head;
        ListNode* fast = &node;
        ListNode* slow = &node;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode rev(0);
        ListNode* ptr = slow->next;
        slow->next = nullptr;
        
        while(ptr){
            ListNode* next = ptr->next;
            ptr->next = rev.next;
            rev.next = ptr;
            ptr = next;
        }
        
        ListNode* to = node.next;
        ListNode* from = rev.next;
        
        while(from){
            ListNode* next = from->next;
            from->next = to->next;
            to->next = from;
            from = next;
            to = to->next->next;
        }
    }
};


