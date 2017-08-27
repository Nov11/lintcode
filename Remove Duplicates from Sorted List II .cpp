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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        if(!head || !head->next){return head;}
        
        ListNode node(0);
        ListNode* ptr = &node;
        
        while(head){
            ListNode* tmp = head;
            int cnt = 0;
            while(tmp->next && tmp->next->val == tmp->val){
                cnt++;
                tmp = tmp->next;
            }
            
            if(cnt == 0){
                head = head->next;
                tmp->next = ptr->next;
                ptr->next = tmp;
                ptr = ptr->next;
            }else{
                head = tmp->next;
            }
        }
        
        return node.next;
    }
};