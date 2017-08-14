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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        if(!head){return head;}
        
        ListNode node(0);
        node.next = head;
        ListNode* ptr = head;
        while(ptr->next){
            if(ptr->val == ptr->next->val){
                ptr->next = ptr->next->next;
            }else{
                ptr = ptr->next;
            }
        }
        
        return node.next;
    }
};