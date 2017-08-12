/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        // Write your code here
        ListNode node(0);
        node.next = head;
        ListNode* ptr = &node;
        
        while(ptr->next != nullptr){
            ListNode* n = ptr->next;
            if(n->val == val){
                ptr->next = n->next;
                free(n);
            }else{
                ptr = ptr->next;
            }
        }
        
        return node.next;
    }
};