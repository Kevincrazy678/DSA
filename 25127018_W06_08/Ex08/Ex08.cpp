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
    TreeNode* prev = nullptr;
    int res = INT_MAX;
    void travel(TreeNode* root){
        //we are using in-order traversal to traverse the tree and we are checking the difference between the value of the current node and the value of the previous node in the in-order traversal, which is the next node in the increasing order search tree, and we are updating the result with the minimum difference found so far, and then we are updating the previous node to the current node before traversing the right subtree
        if(root == nullptr){
            return;
        }
        //we are traversing the left subtree first because in-order traversal visits the left subtree first,
        travel(root->left);
        //then the root, and then the right subtree
        if(prev != nullptr){
            int x = abs(root->val - prev->val);
            res = min(res, x);
        }
        //we are updating the previous node to the current node before traversing the right subtree
        prev = root;
        //then we are traversing the right subtree
        return travel(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        //Time Complexity: O(n) where n is the number of nodes in the tree
        //Space Complexity: O(h) where h is the height of the tree
        travel(root);
        return res;
    }
};

/*
test case 1: fully arranged tree
[4,2,6,1,3]
Ans: 1

test case 2: not fully arranged tree
[1,0,48,null,null,12,49]
Ans: 1

test case 3: two nodes in the tree
[2,1]
Ans: 1
*/