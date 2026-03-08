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
    ListNode* mergeNodes(ListNode* head) {
    	//Complexity: O(n)
        int x = 0;
        ListNode* first = nullptr, *tail = nullptr;
        ListNode* tmp = head->next;
        while(tmp!=nullptr){
        	//We need to check if the value is 0 or not
            if(tmp->val == 0){
            	//Create a new node
                ListNode* node = new ListNode;
                node->val = x;
                //Check if the node first is nullptr or not
                if(first == nullptr){
                    first = node;
                    tail = node;
                }
                else{
                    tail->next = node;
                    tail = node;
                }
                x = 0;
            }
            else{
                x += tmp->val;
            }
            tmp = tmp->next;
        }
        return first;
    }
};
//Test case 1
//Input: [0,3,1,0,4,5,2,0]
//Expected: [4,11]
//Test case 2
//Input: [0,1,0,3,0,2,2,0]
//Expected: [1,3,4]
//Test case 3
//Input: [0,2,1,0,5,2,0,2,3,0]
//Expected: [3,7,5]
