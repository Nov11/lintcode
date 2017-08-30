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
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        int len = 0;
        ListNode* ptr =head;
        while(ptr){
            len++;
            ptr=ptr->next;
        }
        if(len == 0){return nullptr;}
        k %= len;
        if(k == 0){return head;}
        
        k = len - k;
        ListNode node(0);
        node.next = head;
        ptr = &node;
        while(k){
            ptr=ptr->next;
            k--;
        }
        
        ListNode* tail = ptr->next;
        ListNode* second = tail;
        ptr->next = nullptr;
        while(tail->next){
            tail = tail->next;
        }
        tail->next = node.next;
        node.next = second;
        return node.next;
    }
};