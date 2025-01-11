/*
 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* p1 = head ;
        ListNode * p2 = head->next ;
        
        while(p2) {
            int temp = __gcd(p1->val, p2->val) ;
            ListNode * t = new ListNode(temp) ;
            t->next = p1->next ;
            p1->next = t ;
            p1 = p1->next->next ;
            p2 = p2->next ;
        }
        
        return head ;
    }
};
*/