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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        //Complexity: O(n)
        //First we need to travel list1 to a-1
		ListNode* prev1 = list1, *prev2 = list2;
        for(int i=0; i<a-1; i++){
            prev1 = prev1->next;
        }
        //Then we need to merge from a-1(list1) to the first node of list2
        ListNode* tail1 = prev1;
        for(int i=0; i<b-a+1; i++){
            tail1 = tail1->next;
        }
        //We travel to the last node of list2
        prev1->next = prev2;
        while(prev2->next!=nullptr){
            prev2 = prev2->next;
        }
        //Finally, we merge the tail of list2 to the b(list1)
        prev2->next = tail1->next;
        return list1;
    }
};
//Test case 1
//Input: [10,1,13,6,9,5], a = 3, b = 4, [1000000,1000001,1000002]
//Expected: [10,1,13,1000000,1000001,1000002,5]
//Test case 2
//Input: [0,1,2,3,4,5,6], a = 2, b = 5, [1000000,1000001,1000002,1000003,1000004]
//Expected: [0,1,1000000,1000001,1000002,1000003,1000004,6]
//Test case 3
//Input: [0,1,3,8,3,2], a = 1, b = 3, [1000,1001,1000,999]
//Expected: [0,1000,1001,1000,999,3,2]
