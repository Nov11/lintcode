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
     * @param head: A ListNode.
     * @return: A boolean.
     */
    bool isPalindrome(ListNode * head) {
        // write your code here
        if(!head || head->next == nullptr){return true;}
        
        ListNode node(0);
        node.next = head;
        ListNode* fast = &node;
        ListNode* slow = &node;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* second = slow->next;
        ListNode sec(0);
        ListNode* tmp = & sec;
        while(second){
            ListNode* next = second->next;
            second->next = tmp->next;
            tmp->next = second;
            second = next;
        }
        second = sec.next;
        ListNode* first = node.next;
        while(second){
            if(second->val != first->val){return false;}
            second = second->next;
            first = first->next;
        }
        return true;
    }
};