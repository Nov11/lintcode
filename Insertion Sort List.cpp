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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        if(!head){return head;}
        ListNode node(0);
        node.next = head;
        head = head->next;
        node.next->next= nullptr;
        while(head){
            ListNode* ptr = &node;
            ListNode* next = head->next;
            while(ptr->next){
                if(ptr->next->val >= head->val){
                    head->next = ptr->next;
                    ptr->next = head;
                    break;
                }
                ptr = ptr->next;
            }
            if(ptr->next == nullptr){
                head->next = ptr->next;
                ptr->next = head;
            }
            head = next;
        }
        
        return node.next;
    }
};