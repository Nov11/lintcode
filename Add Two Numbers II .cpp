/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
    void work(stack<int>& s, ListNode* node){
        while(node){s.push(node->val);node=node->next;}
    }
public:
    /*
     * @param l1: The first list.
     * @param l2: The second list.
     * @return: the sum list of l1 and l2.
     */
    ListNode * addLists2(ListNode * l1, ListNode * l2) {
        // write your code here
        stack<int> s1;
        work(s1, l1);
        stack<int> s2;
        work(s2, l2);
        
        ListNode node(0);
        ListNode* ptr = & node;
        int carry = 0;
        while(!s1.empty() || !s2.empty()){
            int n1 = 0;
            if(!s1.empty()){
                n1 = s1.top();
                s1.pop();
            }
            int n2 = 0;
            if(!s2.empty()){
                n2 = s2.top();
                s2.pop();
            }
            
            int tmp = n1 + n2 + carry;
            carry = tmp / 10;
            tmp %= 10;
            ListNode* n = new ListNode(tmp);
            n->next = ptr->next;
            ptr->next = n;
        }
        if(carry){
            ListNode* n = new ListNode(1);
            n->next = ptr->next;
            ptr->next = n;
        }
        return node.next;
    }
};