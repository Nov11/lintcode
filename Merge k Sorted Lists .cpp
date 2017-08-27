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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        ListNode node(0);
        ListNode* ptr = &node;
        
        while(!lists.empty()){
            int idx = 0;
            int emptyCnt = 0;
            for(int i = 0; i < lists.size() - emptyCnt;){
                if(lists[i] == nullptr){
                    emptyCnt++;
                    swap(lists[i], lists[lists.size() - emptyCnt]);
                    continue;
                }
                if(lists[i]->val < lists[idx]->val){
                    idx = i;
                }
                i++;
            }
            
            while(emptyCnt){
                emptyCnt--;
                lists.pop_back();
            }
            if(lists.empty()){break;}
            ListNode* n = lists[idx];
            lists[idx] = n->next;
            n->next = ptr->next;
            ptr->next = n;
            ptr = ptr->next;
        }
        
        return node.next;
    }
};


