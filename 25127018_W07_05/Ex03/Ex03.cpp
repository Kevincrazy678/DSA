/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    //time complexity: O(n) where n is the number of nodes in the tree
    //space complexity: O(h) where h is the height of the tree
    //first check if both trees are null, if they are then they are the same
    if(A == nullptr && B == nullptr)return 1;
    //then check if one of the trees is null or if the values of the nodes are different, if they are then they are not the same
    if(A == nullptr || B == nullptr || A->val != B->val)return 0;
    //if the values of the nodes are the same, then we need to check if the left and right subtrees are the same
    return isSameTree(A->left, B->left) && isSameTree(A->right, B->right);
}

/*
Test case 1: both trees are null
Input: A = null, B = null
Answer: 1
Test case 2: one of the trees is null
Input: A = [1,2,3], B = null
Answer: 0
Test case 3: the values of the nodes are different
Input: A = [1,2,3], B = [1,2,4]
Answer: 0
*/
