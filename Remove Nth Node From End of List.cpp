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
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        ListNode node(0);
        node.next = head;
        
        ListNode* ptr1 = &node;
        ListNode* ptr2 = ptr1;
        for(int i = 0; i <= n; i++){
            ptr2 = ptr2->next;
        }
        
        while(ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        ptr1->next = ptr1->next->next;
        
        return node.next;
    }
};


