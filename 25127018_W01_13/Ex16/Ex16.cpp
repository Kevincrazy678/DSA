/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* tmp = head;
        //Complexity: O(n)
        while(tmp->next!=nullptr){
            int x = gcd(tmp->val, tmp->next->val);
            //We can create new node here
            ListNode* node = new ListNode;
            node->val = x;
            //We move new node to between of 2 old nodes
            node->next = tmp->next;
            tmp->next = node; 
            tmp = tmp->next->next;
        }
        return head;
    }
};
//Test case 1
//Input: [18,6,10,3]
//Expected: [18,6,6,2,10,1,3]
//Test case 2
//Input: [7]
//Expected: [7]
//Test case 3
//Input: [7, 8 ,9]
//Expected: [7,1,8,1,9]
