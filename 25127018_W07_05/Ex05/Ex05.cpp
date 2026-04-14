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
    bool check(TreeNode* t, TreeNode*p){
        // 1. Both are null, then they are symmetric
        if(t == nullptr && p == nullptr)return true;
        // 2. One of them is null or different with others, then they are not symmetric
        if(t == nullptr || p == nullptr || t->val != p->val)return false;
        // 3. Check the left of t with the right of p, and the right of t with the left of p
        return check(t->left, p->right) && check(t->right, p->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        //time complexity: O(n) with n is the number of nodes in the tree, we need to check each node once
        //space complexity: O(h) with h is the height of the tree, in the worst case, we need to check all the nodes in one level of the tree
        return check(root->left, root->right);
    }
};

/*
Test case 1: the left and right subtrees are symmetric
Input: root = [1,2,2,3,4,4,3]
Answer: true

Test case 2: the left and right subtrees are not symmetric
Input: root = [1,2,2,null,3,null,3]
Answer: false

Test case 3: only one node in the tree, which is symmetric
Input: root = [1]
Answer: true
*/