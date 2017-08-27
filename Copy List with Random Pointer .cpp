/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        RandomListNode node(0);
        RandomListNode* ptr = &node;
        unordered_map<RandomListNode*, RandomListNode*> hash;
        while(head){
            RandomListNode* n = nullptr;
            if(hash.find(head) != hash.end()){
                n = hash[head];
            }else{
                n = new RandomListNode(head->label);
                hash[head] = n;  
            }
            
            if(head->random){
                if(hash.find(head->random) != hash.end()){
                    n->random = hash[head->random];
                }else{
                    RandomListNode* r = new RandomListNode(head->random->label);
                    hash[head->random] = r;
                    n->random = r;
                }
            }
            n->next = ptr->next;
            ptr->next = n;
            ptr = ptr->next;
            head = head->next;
        }
        
        return node.next;
    }
};