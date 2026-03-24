/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int res = 0;
    //we are using in-order traversal to traverse the tree and check if the value of the node is in the range [low, high] and if it is, we add it to the result
    void travel(TreeNode* root, int low, int high){
        if(root == nullptr){
            return;
        }
        //we are traversing the left subtree first because in-order traversal visits the left subtree first,
        travel(root->left, low, high);
        if(root != nullptr){
            if(root->val >= low && root->val <= high){
                res += root->val;
            }
        }
        //then the root, and then the right subtree
        travel(root->right, low, high);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        //time complexity: O(n) where n is the number of nodes in the tree
        //space complexity: O(h) where h is the height of the tree
        travel(root, low, high);
        return res;
    }
};

/*
test case 1: normally arranged tree with some nodes in the range and some nodes out of the range
[10,5,15,3,7,null,18], low = 7, high = 15
Ans: 32
    
test case 2: there are no nodes in the range, so the result should be 0  
[10,5,15,3,7,13,18,1,null,6], low = 19, high = 29
Ans: 0

test case 3: only one node in the tree and it is in the range 
[1], low = 1, high = 1
Ans: 1
*/