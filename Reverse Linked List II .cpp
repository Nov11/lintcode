/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        ListNode node(0);
        node.next = head;
        
        ListNode* ppm = &node;
        int tmp = m - 1;
        while(tmp && ppm){
            ppm = ppm->next;
            tmp--;
        }
        if(!ppm){return head;}
        
        ListNode* pn = ppm;
        tmp = n - m + 1;
        while(tmp && pn){
            pn = pn->next;
            tmp--;
        }
        
        ListNode* end = pn ? pn->next : pn;
        ListNode* iter = ppm->next;
        ppm->next = end;
        while(iter != end){
            ListNode* tmp = iter->next;
            iter->next = ppm->next;
            ppm->next = iter;
            iter = tmp;
        }
        return node.next;
    }
};
