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
    bool hasCycle(ListNode *head) {
        
        unordered_set<ListNode*> hashtable;
        while(head!=NULL){
            if(hashtable.find(head)!=hashtable.end()){
                return true;
            }
            hashtable.insert(head);
            head=head->next;
        }
        return false;

    }
};