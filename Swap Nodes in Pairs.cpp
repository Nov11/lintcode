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
    
    /*
     * @param head: a ListNode
     * @return: a ListNode
     */
    ListNode * swapPairs(ListNode * head) {
        // write your code here
        if(!head){return head;}
        ListNode node(0);
        node.next = head;
        ListNode* ptr = head;
        while(ptr && ptr->next){
            swap(ptr->val, ptr->next->val);
            ptr = ptr->next->next;
        }
        
        return node.next;
    }
};