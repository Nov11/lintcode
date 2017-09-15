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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        if(!head){return head;}
        
        ListNode node(0);
        node.next = head;
        ListNode* slow= &node;
        ListNode* fast =&node;
        
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                break;
            }
        }
        
        if(head->next == nullptr || fast != slow){return nullptr;}
        
        ListNode* ptr = &node;
        while(ptr!=slow){
            slow=slow->next;
            ptr=ptr->next;
        }
        return ptr;
    }
};


