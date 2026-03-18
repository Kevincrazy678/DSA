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
        if(root == nullptr){
            return;
        }
        travel(root->left);
        if(prev != nullptr){
            int x = abs(root->val - prev->val);
            res = min(res, x);
        }
        prev = root;
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